#pragma once


#include<string>
#include"SmsSubmitMsg.h"
#include"SmsReportMsg.h"
#include"SmsDeliverMsg.h"
#include"SmsBalanceMsg.h"
#include"SmsKeyWordMsg.h"
#include"SmsBlackListMsg.h"
#pragma comment(lib, "libcurl.lib")
using namespace std;


typedef  void (*callBackFunc)(const char*buffer, size_t size, size_t nmemb, string &stream); 
/********************初始化程序库不能多次初始化*******************/
extern "C"   __declspec(dllexport)bool initLibrary(); 
/***************************短信下行*************************************/
extern "C"   __declspec(dllexport)bool smsSubmitXml(string url,SmsSubmitMsg msg,void(*callBackFunc));
extern "C"   __declspec(dllexport)bool smsSubmitJson(string url,SmsSubmitMsg msg,void(*callBackFunc)); 

extern "C"   __declspec(dllexport)bool getReportXml(string url,SmsReportMsg msg,void(*callBackFunc));
extern "C"   __declspec(dllexport)bool getReportJson(string url,SmsReportMsg msg,void(*callBackFunc));

extern "C"   __declspec(dllexport)bool getDeliverXml(string url,SmsDeliverMsg msg,void(*callBackFunc));
extern "C"   __declspec(dllexport)bool getDeliverJson(string url,SmsDeliverMsg msg,void(*callBackFunc));

extern "C"   __declspec(dllexport)bool getBalanceXml(string url,SmsBalanceMsg msg,void(*callBackFunc));
extern "C"   __declspec(dllexport)bool getBalanceJson(string url,SmsBalanceMsg msg,void(*callBackFunc));

extern "C"   __declspec(dllexport)bool checkKeyWordXml(string url,SmsKeyWordMsg msg,void(*callBackFunc));
extern "C"   __declspec(dllexport)bool checkKeyWordJson(string url,SmsKeyWordMsg msg,void(*callBackFunc));

extern "C"   __declspec(dllexport)bool checkBlackListXml(string url,SmsBlackListMsg msg,void(*callBackFunc));
extern "C"   __declspec(dllexport)bool checkBlackListJson(string url,SmsBlackListMsg msg,void(*callBackFunc));

