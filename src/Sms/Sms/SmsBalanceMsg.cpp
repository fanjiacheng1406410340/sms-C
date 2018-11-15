#include "stdafx.h"
#include "SmsBalanceMsg.h"
#include"MD5.h"

SmsBalanceMsg::SmsBalanceMsg(void)
{
}


SmsBalanceMsg::~SmsBalanceMsg(void)
{
}

string SmsBalanceMsg::toXml()
{
	string balanceMsg="";
	balanceMsg.append("message=");
    balanceMsg.append("<?xml version='1.0' encoding='UTF-8' ?>");
	balanceMsg.append("<message>");
    balanceMsg.append("<account>"+account+"</account>");
    balanceMsg.append("<password>"+md5(password)+"</password>");
    balanceMsg.append("</message>");
	return balanceMsg;
}

string SmsBalanceMsg::toJson()
{
	string balanceMsg="";
	balanceMsg.append("{\"account\":\""+account+"\"");
	balanceMsg.append(",\"password\":\""+md5(password)+"\"}");
	return balanceMsg;

}
