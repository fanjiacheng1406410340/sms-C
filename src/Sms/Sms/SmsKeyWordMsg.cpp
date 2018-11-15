#include "stdafx.h"
#include "SmsKeyWordMsg.h"
#include"MD5.h"

SmsKeyWordMsg::SmsKeyWordMsg(void)
{
}


SmsKeyWordMsg::~SmsKeyWordMsg(void)
{
}

string SmsKeyWordMsg::toXml()
{
	string keyWordMsg="";
	keyWordMsg.append("message=");
	keyWordMsg.append("<?xml version='1.0' encoding='UTF-8' ?>");
	keyWordMsg.append("<message>");
	keyWordMsg.append("<account>"+account+"</account>");
	keyWordMsg.append("<password>"+md5(password)+"</password>");
	keyWordMsg.append("<content>"+content+"</content>");
	keyWordMsg.append("</message>");
	return keyWordMsg;
}
string  SmsKeyWordMsg::toJson()
{
    string keyWordMsg="";
	keyWordMsg.append("{\"account\":\""+account+"\"");
	keyWordMsg.append(",\"password\":\""+md5(password)+"\"");
	keyWordMsg.append(",\"content\":\""+content+"\"}");
	return keyWordMsg;
}
