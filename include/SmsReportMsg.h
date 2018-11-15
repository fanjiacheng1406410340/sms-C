#pragma once
#include<string>
using namespace std;
class SmsReportMsg
{
public:
	SmsReportMsg(void);
	~SmsReportMsg(void);
	string account;
	string password;
	string phones;
	string msgId;
	string toXml();
	string toJson();
};

