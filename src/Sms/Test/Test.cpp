// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Sms.h"
#include <iostream>
#include"Config.h"
#include"encrypt.h"

#pragma comment(lib, "Sms.lib")
static size_t callBackResponse( const char*buffer, size_t size, size_t nmemb, string &stream)
{

	
    unsigned long sizes = size * nmemb;
	string result(buffer);
	result=UTF8ToGBK(result);
	printf(" response data：【%s】\r\n", result.c_str() );
    return sizes;  

}  

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"接口调用命令\r\n 短信下行:a 获取状态报告:b 获取上行:c 查询余额:d\r\n 检测黑名单:e 检测敏感词:f"<<endl;
	system( "PAUSE ");
	
	Config config;
	if(!config.initConfig("config.xml"))
	{
		 printf( "Failed to  init config ");
	}
	string serviceUrl=config.serviceUrl;
	string dataType=config.dataType;
    string account=config.account;
	string password=config.password;
	string phones=config.phones;
	string content=config.content;
	string sign=config.sign;
	string msgId=config.msgId;
	string subCode=config.subCode;
	string sendTime=config.sendTime;
	bool result=initLibrary();
    char str[5];
	string url;
	while(1)
	{
		cout<<"请输入接口调用命令:"<<endl;
		cin>>str;
		string command(str);
		if(command=="a")
		{
			SmsSubmitMsg msg;
			msg.account=account;
			msg.password=password;
			msg.msgId=msgId;
			msg.phones=phones;
			msg.content=content;
			msg.sendTime=sendTime;
			msg.sign=sign;
			msg.subCode=subCode;
			if(dataType=="0")
			{
				url=serviceUrl+"/http/sms/Submit";
				smsSubmitXml(url,msg,callBackResponse);
			}
			else
			{
			   url=serviceUrl+"/json/sms/Submit";
			   smsSubmitJson(url,msg,callBackResponse);
			}
		
		}
		else if(command=="b")
		{
			SmsReportMsg msg;
			msg.account=account;
			msg.password=password;
			if(dataType=="0")
			{
				url=serviceUrl+"/http/sms/Report";
				getReportXml(url,msg,callBackResponse);
			}
			else
			{
				url=serviceUrl+"/json/sms/Report";
				getReportJson(url,msg,callBackResponse);
			}
		}
		else if(command=="c")
		{
			SmsDeliverMsg msg;
			msg.account=account;
			msg.password=password;
			if(dataType=="0")
			{
				url=serviceUrl+"/http/sms/Deliver";
				getDeliverXml(url,msg,callBackResponse);
			}
			else
			{
				url=serviceUrl+"/json/sms/Deliver";
				getDeliverJson(url,msg,callBackResponse);
			}
		}
		else if(command=="d")
		{
			SmsBalanceMsg msg;
			msg.account=account;
			msg.password=password;
			if(dataType=="0")
			{
				url=serviceUrl+"/http/sms/Balance";
				getBalanceXml(url,msg,callBackResponse);
			}
			else
			{
				url=serviceUrl+"/json/sms/Balance";
				getBalanceJson(url,msg,callBackResponse);
			}
		}
		else if(command=="e")
		{
			SmsBlackListMsg msg;
			msg.account=account;
			msg.password=password;
			msg.phones=phones;
			
			if(dataType=="0")
			{
				url=serviceUrl+"/http/sms/BlackListCheck";
				checkBlackListXml(url,msg,callBackResponse);
			}
			else
			{
				url=serviceUrl+"/json/sms/BlackListCheck";
				checkBlackListJson(url,msg,callBackResponse);
			}
		
		}
		else if(command=="f")
		{
			SmsKeyWordMsg msg;
			msg.account=account;
			msg.password=password;
			msg.content=content;
			if(dataType=="0")
			{
				url=serviceUrl+"/http/sms/KeywordCheck";
				checkKeyWordXml(url,msg,callBackResponse);
			}
			else
			{
				url=serviceUrl+"/json/sms/KeywordCheck";
				checkKeyWordJson(url,msg,callBackResponse);
			}
		
		}
		
	
	}
	return 0;
}

