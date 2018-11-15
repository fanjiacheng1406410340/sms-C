#pragma once
#include<string>
using namespace std;
class SmsBalanceMsg
{
public:
	SmsBalanceMsg(void);
	~SmsBalanceMsg(void);
	string account;
	string password;
	string toXml();
	string toJson();
};

