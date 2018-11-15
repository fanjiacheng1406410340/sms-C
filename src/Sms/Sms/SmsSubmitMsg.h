#pragma once
#include<string>
using namespace std;
class __declspec(dllexport) SmsSubmitMsg
{
public:
	 SmsSubmitMsg(void);
	  ~SmsSubmitMsg(void);
	
	string account;
	string password;
	string phones;
	string content;
	string sign;
	string msgId;
	string subCode;
	string sendTime;
	string toXml();
	string toJson();
};

