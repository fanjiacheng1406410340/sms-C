#pragma once
#include<string>
#include"tinyxml.h"
using namespace std;
class Config
{
public:
	
	Config();
	~Config(void);
	string serviceUrl;
	string dataType;
	string account;
	string password;
	string msgId;
	string phones;
	string content;
	string sign;
	string subCode;
	string sendTime;
	bool initConfig(string filePath);
private:
	TiXmlElement* root;
	bool  GetNodePointerByName(TiXmlElement* pParentEle,string &strNodeName,TiXmlElement* &Node) ;

};

