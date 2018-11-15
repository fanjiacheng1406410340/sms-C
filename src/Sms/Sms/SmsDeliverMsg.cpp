#include "stdafx.h"
#include "SmsDeliverMsg.h"
#include"MD5.h"


SmsDeliverMsg::SmsDeliverMsg(void)
{
}


SmsDeliverMsg::~SmsDeliverMsg(void)
{
}

string SmsDeliverMsg::toXml()
{
	string smsDeliverMsg="";
	smsDeliverMsg.append("message=");
	smsDeliverMsg.append("<?xml version='1.0' encoding='UTF-8' ?>");
	smsDeliverMsg.append("<message>");
	smsDeliverMsg.append("<account>"+account+"</account>");
	smsDeliverMsg.append("<password>"+md5(password)+"</password>");
	smsDeliverMsg.append("</message>");
	return smsDeliverMsg;

}
string SmsDeliverMsg::toJson()
{
	string smsDeliverMsg="";
	smsDeliverMsg.append("{\"account\":\""+account+"\"");
	smsDeliverMsg.append(",\"password\":\""+md5(password)+"\"}");
	return smsDeliverMsg;
}