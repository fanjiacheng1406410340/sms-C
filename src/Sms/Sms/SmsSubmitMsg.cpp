#include "stdafx.h"
#include "SmsSubmitMsg.h"
#include"MD5.h"

SmsSubmitMsg::SmsSubmitMsg(void)
{
}


SmsSubmitMsg::~SmsSubmitMsg(void)
{
}

string SmsSubmitMsg::toXml()
{

      string result="";
      result.append("message=");
	  result.append("<?xml version='1.0' encoding='UTF-8' ?>");
	  result.append("<message>");
	  result.append("<account>"+account+"</account>");
	  result.append("<password>"+md5(password)+"</password>");
	  result.append("<phones>"+phones+"</phones>");
	  result.append("<content>"+content+"</content>");
	  result.append("<sign>"+sign+"</sign>");
	  result.append("subcode>"+subCode+"subcode>");
	  result.append("<sendtime>"+sendTime+"</sendtime>");
	  result.append("</message>");
      return result;
}
string SmsSubmitMsg::toJson()
{
	string result="";
	result.append("{\"account\":\""+account+"\"");
	result.append(",\"password\":\""+md5(password)+"\"");
	result.append(",\"msgid\":\""+msgId+"\"");
	result.append(",\"phones\":\""+phones+"\"");
	result.append(",\"content\":\""+content+"\"");
	result.append(",\"sign\":\""+sign+"\"");
	result.append(",\"subcode\":\""+subCode+"\"");
	result.append(",\"sendtime\":\""+sendTime+"\"}");
	return result;

}
