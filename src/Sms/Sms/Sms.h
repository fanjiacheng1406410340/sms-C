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

/********************初始化程序库不能多次初始化(线程不安全,只能在主线程调用)*******************/
extern "C"   __declspec(dllexport)bool initLibrary(); 

/***************************发送短信(xml数据格式)*************************************/
extern "C"   __declspec(dllexport)bool smsSubmitXml(string url,SmsSubmitMsg msg,void(*callBackFunc));
/***************************发送短信(JSON数据格式)*************************************/

extern "C"   __declspec(dllexport)bool smsSubmitJson(string url,SmsSubmitMsg msg,void(*callBackFunc)); 
/***************************获取状态报告(xml数据格式)*************************************/
extern "C"   __declspec(dllexport)bool getReportXml(string url,SmsReportMsg msg,void(*callBackFunc));
/***************************获取状态报告(JSON数据格式)*************************************/
extern "C"   __declspec(dllexport)bool getReportJson(string url,SmsReportMsg msg,void(*callBackFunc));

/***************************获取上行短信(xml数据格式)*************************************/
extern "C"   __declspec(dllexport)bool getDeliverXml(string url,SmsDeliverMsg msg,void(*callBackFunc));
/***************************获取上行短信(JSON数据格式)*************************************/
extern "C"   __declspec(dllexport)bool getDeliverJson(string url,SmsDeliverMsg msg,void(*callBackFunc));

/***************************获取余额(xml数据格式)*************************************/
extern "C"   __declspec(dllexport)bool getBalanceXml(string url,SmsBalanceMsg msg,void(*callBackFunc));
/***************************获取余额(JSON数据格式)*************************************/
extern "C"   __declspec(dllexport)bool getBalanceJson(string url,SmsBalanceMsg msg,void(*callBackFunc));

/***************************检测黑名单(xml数据格式)*************************************/
extern "C"   __declspec(dllexport)bool checkKeyWordXml(string url,SmsKeyWordMsg msg,void(*callBackFunc));
/***************************检测黑名单(JSON数据格式)*************************************/
extern "C"   __declspec(dllexport)bool checkKeyWordJson(string url,SmsKeyWordMsg msg,void(*callBackFunc));

/***************************检测敏感词(xml数据格式)*************************************/
extern "C"   __declspec(dllexport)bool checkBlackListXml(string url,SmsBlackListMsg msg,void(*callBackFunc));
/***************************检测敏感词(JSON数据格式)*************************************/
extern "C"   __declspec(dllexport)bool checkBlackListJson(string url,SmsBlackListMsg msg,void(*callBackFunc));

/***********************************释放程序库链接资源(线程不安全,只能在主线程调用)***************************/
extern "C"   __declspec(dllexport)void releaseLibrary();

