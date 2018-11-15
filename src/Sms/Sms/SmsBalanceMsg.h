#pragma once
#include<string>
using namespace std;
class  __declspec(dllexport) SmsBalanceMsg
{
public:
	 SmsBalanceMsg(void);
	 ~SmsBalanceMsg(void);
	string account;
	string password;
	string toXml();
	string toJson();
};

