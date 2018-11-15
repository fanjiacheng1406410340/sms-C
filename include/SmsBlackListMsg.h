#pragma once
#include<string>
using namespace std;
class SmsBlackListMsg
{
public:
	SmsBlackListMsg(void);
	~SmsBlackListMsg(void);
	string account;
	string password;
	string phones;
	string toXml();
	string toJson();
};

