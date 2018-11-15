#include "stdafx.h"
#include "SmsReportMsg.h"
#include"MD5.h"

SmsReportMsg::SmsReportMsg(void)
{
}


SmsReportMsg::~SmsReportMsg(void)
{
}

string SmsReportMsg::toXml()
{
	string smsReportMsg="";
	smsReportMsg.append("message=");
	smsReportMsg.append("<?xml version='1.0' encoding='UTF-8' ?>");
	smsReportMsg.append("<message>");
    smsReportMsg.append("<account>"+account+"</account>");
	smsReportMsg.append("<password>"+md5(password)+"</password>");
	smsReportMsg.append("</message>");
	return smsReportMsg;

}
string SmsReportMsg::toJson()
{
	string smsReportMsg="";
	smsReportMsg.append("{\"account\":\""+account+"\"");
    smsReportMsg.append(",\"password\":\""+md5(password)+"\"");
	smsReportMsg.append(",\"msgid\":\""+msgId+"\"");
	smsReportMsg.append(",\"phone\":\""+phones+"\"}");
	return smsReportMsg;
}
