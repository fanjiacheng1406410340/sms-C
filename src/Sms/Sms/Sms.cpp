// Sms.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
// TestSms.cpp : 定义 DLL 应用程序的导出函数。
//




#include"Sms.h"
#include "curl/curl.h" 
#include"encrypt.h"


CURL *curl;
bool doPost(string url,string data,void(*callBackFunc))
{
	CURLcode code;
	code=curl_easy_setopt(curl, CURLOPT_URL,url.c_str() );
	if (code != CURLE_OK)
    {
        printf("Failed to set URL [%s]\n", code);
		return false;
        
    }
	code = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callBackFunc);
    if (code != CURLE_OK)
    {
        printf( "Failed to set writer [%s]\n",  code);
		return false;
        
    }
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
	code = curl_easy_perform(curl);
    if(CURLE_OK != code)
	{
	    printf( "Failed to request errorcode:[%d]\n", code );
		return false;
	}
}
	
bool initLibrary()
{
	CURLcode code;
	code=curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if (code != CURLE_OK)
    {
        printf( "Failed to global init default [%d]\n", code );
        return false;
    } 
		
	string error;
	string httpHeader="";
	struct curl_slist *headers=NULL;
	code=curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error);
	if (code != CURLE_OK)
    {
        printf( "Failed to set error buffer [%d]\n", code );
	   return false;
        
    }
	  
	httpHeader="Content-Type:application/x-www-form-urlencoded; charset=UTF-8";
	headers = curl_slist_append(headers,httpHeader.c_str());
	code=curl_easy_setopt(curl, CURLOPT_HTTPHEADER,headers);
	if (code != CURLE_OK)
    {
        printf( "Failed to set header [%d]\n", code );
        return false;
    }
	code=curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT,10);
	code=curl_easy_setopt(curl, CURLOPT_TIMEOUT,20);
	return true;
}

bool smsSubmitXml(string url,SmsSubmitMsg msg,void(*callBackFunc))
{
	string data=msg.toXml();
	if(url=="")
	{
		url="http://wt.3tong.net/http/sms/Submit";
	}
	bool result=true;
	printf("短信下行 request data：【%s】\r\n", UTF8ToGBK(data).c_str() );
	result=doPost(url,data,callBackFunc);
	return result;
	
}

bool smsSubmitJson(string url,SmsSubmitMsg msg,void(*callBackFunc))
{
	string data=msg.toJson();
	if(url=="")
	{
		url="http://wt.3tong.net/json/sms/Submit";
	}
	bool result=false;
	printf("短信下行 request data：【%s】\r\n", UTF8ToGBK(data).c_str() );
	result=doPost(url,data,callBackFunc);
    return result;

}

bool getReportXml(string url,SmsReportMsg msg,void(*callBackFunc))
{
	string data=msg.toXml();
	if(url=="")
	{
		url="http://wt.3tong.net/http/sms/Report";
	}
	bool result=false;
	printf("获取状态报告 request data：【%s】\r\n", UTF8ToGBK(data).c_str() );
	result=doPost(url,data,callBackFunc);
	return result;
}

bool getReportJson(string url,SmsReportMsg msg,void(*callBackFunc))
{
	string data=msg.toJson();
	if(url=="")
	{
		url="http://wt.3tong.net/json/sms/Report";
	}
	bool result=false;
	printf("获取状态报告 request data：【%s】\r\n", UTF8ToGBK(data).c_str() );
	result=doPost(url,data,callBackFunc);
	return result;
}

bool getDeliverXml(string url,SmsDeliverMsg msg,void(*callBackFunc))
{
	string data=msg.toXml();
	if(url=="")
	{
		url="http://wt.3tong.net/http/sms/Deliver";
	}
	bool result=false;
	printf("获取上行 request data：【%s】\r\n", UTF8ToGBK(data).c_str() );
	result=doPost(url,data,callBackFunc);
	return result;
}
bool getDeliverJson(string url,SmsDeliverMsg msg,void(*callBackFunc))
{
	string data=msg.toJson();
	if(url=="")
	{
		url="http://wt.3tong.net/json/sms/Deliver";
	}
	bool result=false;
	printf("获取上行 request data：【%s】\r\n", UTF8ToGBK(data).c_str() );
	result=doPost(url,data,callBackFunc);
	return result;
}



bool getBalanceXml(string url,SmsBalanceMsg msg,void(*callBackFunc))
{

	string data=msg.toXml();
	if(url=="")
	{
		url="http://wt.3tong.net/http/sms/Balance";
	}
	bool result=false;
	printf("查询余额 request data：【%s】\r\n", UTF8ToGBK(data).c_str() );
	result=doPost(url,data,callBackFunc);
	return result;
}

bool getBalanceJson(string url,SmsBalanceMsg msg,void(*callBackFunc))
{
	string data=msg.toJson();
	if(url=="")
	{
		url="http://wt.3tong.net/json/sms/Balance";
	}
	bool result=false;
	printf("查询余额 request data：【%s】\r\n", UTF8ToGBK(data).c_str() );
	result=doPost(url,data,callBackFunc);
	return result;

}

bool checkKeyWordXml(string url,SmsKeyWordMsg msg,void(*callBackFunc))
{

	string data=msg.toXml();
	if(url=="")
	{
		url="http://wt.3tong.net/http/sms/KeywordCheck";
	}
	bool result=false;
	printf("检测敏感词 request data：【%s】\r\n", UTF8ToGBK(data).c_str() );
	result=doPost(url,data,callBackFunc);
	return result;
}

bool checkKeyWordJson(string url,SmsKeyWordMsg msg,void(*callBackFunc))
{
	string data=msg.toJson();
	if(url=="")
	{
		url="http://wt.3tong.net/json/sms/KeywordCheck";
	}
	bool result=false;
	printf("检测敏感词 request data：【%s】\r\n", UTF8ToGBK(data).c_str() );
	result=doPost(url,data,callBackFunc);
	return result;
}

bool checkBlackListXml(string url,SmsBlackListMsg msg,void(*callBackFunc))
{

	string data=msg.toXml();
	if(url=="")
	{
		url="http://wt.3tong.net/http/sms/BlackListCheck";
	}
	bool result=false;
	printf("检测黑名单 request data：【%s】\r\n", UTF8ToGBK(data).c_str() );
	result=doPost(url,data,callBackFunc);
	return result;
}

bool checkBlackListJson(string url,SmsBlackListMsg msg,void(*callBackFunc))
{

	string data=msg.toJson();
	if(url=="")
	{
		url="http://wt.3tong.net/json/sms/BlackListCheck";
	}
	bool result=false;
	printf("检测黑名单 request data：【%s】\r\n", UTF8ToGBK(data).c_str() );
	result=doPost(url,data,callBackFunc);
	return result;
}

void releaseLibrary()
{
	curl_easy_cleanup(curl);
}



