#pragma once
#include<string>
using namespace std;
class SmsKeyWordMsg
{
public:
	SmsKeyWordMsg(void);
	~SmsKeyWordMsg(void);
	string account;
	string password;
	string content;
	string toXml();
	string toJson();
};

