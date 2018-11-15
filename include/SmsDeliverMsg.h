#pragma once
#include<string>
using namespace std;
class SmsDeliverMsg
{
public:
	SmsDeliverMsg(void);
	~SmsDeliverMsg(void);
	string account;
	string password;
	string toXml();
	string toJson();
};

