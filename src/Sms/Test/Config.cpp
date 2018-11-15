#include "stdafx.h"
#include "Config.h"


Config::Config()
{
	
	
	
	
}


Config::~Config(void)
{
}

bool Config::initConfig(string filePath)
{
	TiXmlDocument doc(filePath.c_str());
	bool loadOkay=doc.LoadFile();
	if(!loadOkay)
	  printf( "Failed to load file %s",filePath );
	else
	 root = doc.RootElement();
	if(root==NULL)
		return false;
	TiXmlElement * element;

	if(!GetNodePointerByName(root,(string)"serviceUrl",element))
	{
		printf( "Failed to get element %s value","serviceUrl" );
		return false;
	}
	if(element!=nullptr)
	{
		if(element->GetText())
	      serviceUrl=element->GetText();
	}
	element=nullptr;
	if(!GetNodePointerByName(root,(string)"dataType",element))
	{
		printf( "Failed to get element %s value","dataType" );
		return false;
	}
	if(element!=nullptr)
	{
		if(element->GetText())
		 dataType=element->GetText();
	}
	  
	element=nullptr;
	TiXmlElement *messageElement;
	if(!GetNodePointerByName(root,(string)"message",messageElement))
	{
		printf( "Failed to get element %s ","message" );
		return false;
	}
	element=nullptr;
	if(!GetNodePointerByName(messageElement,(string)"account",element))
	{
		printf( "Failed to get element %s value","account" );
		return false;
	}
	if(element!=nullptr)
	 account=element->GetText();
	element=nullptr;
	if(!GetNodePointerByName(messageElement,(string)"password",element))
	{
		printf( "Failed to get element %s value","password" );
		return false;
	}
	if(element!=nullptr)
	{
		if(element->GetText())
		  password=element->GetText();
	}
	
	element=nullptr;
	if(!GetNodePointerByName(messageElement,(string)"msgId",element))
	{
		printf( "Failed to get element %s value","msgId" );
		return false;
	}
	if(element!=nullptr)
	{
		if(element->GetText())
			msgId=element->GetText();
	}
	 
	element=nullptr;
	if(!GetNodePointerByName(messageElement,(string)"phones",element))
	{
		printf( "Failed to get element %s value","phones" );
		return false;
	}
	if(element!=nullptr)
	{
		if(element->GetText())
		  phones=element->GetText();
	}
	element=nullptr; 
	if(!GetNodePointerByName(messageElement,(string)"content",element))
	{
		printf( "Failed to get element %s value","content" );
		return false;
	}
	if(element!=nullptr)
	{
		if(element->GetText())
			content=element->GetText();
	}

	element=nullptr; 
	if(!GetNodePointerByName(messageElement,(string)"sign",element))
	{
		printf( "Failed to get element %s value","sign" );
		return false;
	}
	if(element!=nullptr)
	{
		if(element->GetText())
			sign=element->GetText();
	}

	element=nullptr;
	if(!GetNodePointerByName(messageElement,(string)"subcode",element))
	{
		printf( "Failed to get element %s value","subcode" );
		return false;
	}
	if(element!=nullptr)
	{
	   if(element->GetText())
	     subCode=element->GetText();
	}
	element=nullptr;
	if(!GetNodePointerByName(messageElement,(string)"sendtime",element))
	{
		printf( "Failed to get element %s value","sendtime" );
		return false;
	}
	if(element!=nullptr)
	{
	   if(element->GetText())
		 sendTime=element->GetText();
	}

	
	return true;
}
bool Config::GetNodePointerByName(TiXmlElement* pParentEle,string &strNodeName,TiXmlElement* &Node)
{
	  // 假如等于父节点名，就退出  
      if (strNodeName== pParentEle->Value())  
      {  
          Node =  pParentEle;  
          return true;  
      }  
     TiXmlElement* pEle =  pParentEle;    
     for (pEle =  pParentEle->FirstChildElement(); pEle; pEle = pEle->NextSiblingElement())    
     {    
           //递归处理子节点，获取节点指针  
           if(GetNodePointerByName(pEle,strNodeName,Node))  
               return true;  
      }    
      return false;  
}