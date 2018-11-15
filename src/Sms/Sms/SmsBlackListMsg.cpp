#include "stdafx.h"
#include "SmsBlackListMsg.h"
#include"MD5.h"


SmsBlackListMsg::SmsBlackListMsg(void)
{
}


SmsBlackListMsg::~SmsBlackListMsg(void)
{
}

string SmsBlackListMsg::toXml()
{
	string blackListMsg="";
    blackListMsg.append("message=");
	blackListMsg.append("<?xml version='1.0' encoding='UTF-8' ?>");
	blackListMsg.append("<message>");
	blackListMsg.append("<account>"+account+"</account>");
	blackListMsg.append("<password>"+md5(password)+"</password>");
	blackListMsg.append("<phones>"+phones+"</phones>");
	blackListMsg.append("</message>");
	return  blackListMsg;

}
string SmsBlackListMsg::toJson()
{
	string blackListMsg="";
	blackListMsg.append("{\"account\":\""+account+"\"");
	blackListMsg.append(",\"password\":\""+md5(password)+"\"");
	blackListMsg.append(",\"phones\":\""+phones+"\"}");
	return  blackListMsg;
}
