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

/********************��ʼ������ⲻ�ܶ�γ�ʼ��(�̲߳���ȫ,ֻ�������̵߳���)*******************/
extern "C"   __declspec(dllexport)bool initLibrary(); 

/***************************���Ͷ���(xml���ݸ�ʽ)*************************************/
extern "C"   __declspec(dllexport)bool smsSubmitXml(string url,SmsSubmitMsg msg,void(*callBackFunc));
/***************************���Ͷ���(JSON���ݸ�ʽ)*************************************/

extern "C"   __declspec(dllexport)bool smsSubmitJson(string url,SmsSubmitMsg msg,void(*callBackFunc)); 
/***************************��ȡ״̬����(xml���ݸ�ʽ)*************************************/
extern "C"   __declspec(dllexport)bool getReportXml(string url,SmsReportMsg msg,void(*callBackFunc));
/***************************��ȡ״̬����(JSON���ݸ�ʽ)*************************************/
extern "C"   __declspec(dllexport)bool getReportJson(string url,SmsReportMsg msg,void(*callBackFunc));

/***************************��ȡ���ж���(xml���ݸ�ʽ)*************************************/
extern "C"   __declspec(dllexport)bool getDeliverXml(string url,SmsDeliverMsg msg,void(*callBackFunc));
/***************************��ȡ���ж���(JSON���ݸ�ʽ)*************************************/
extern "C"   __declspec(dllexport)bool getDeliverJson(string url,SmsDeliverMsg msg,void(*callBackFunc));

/***************************��ȡ���(xml���ݸ�ʽ)*************************************/
extern "C"   __declspec(dllexport)bool getBalanceXml(string url,SmsBalanceMsg msg,void(*callBackFunc));
/***************************��ȡ���(JSON���ݸ�ʽ)*************************************/
extern "C"   __declspec(dllexport)bool getBalanceJson(string url,SmsBalanceMsg msg,void(*callBackFunc));

/***************************��������(xml���ݸ�ʽ)*************************************/
extern "C"   __declspec(dllexport)bool checkKeyWordXml(string url,SmsKeyWordMsg msg,void(*callBackFunc));
/***************************��������(JSON���ݸ�ʽ)*************************************/
extern "C"   __declspec(dllexport)bool checkKeyWordJson(string url,SmsKeyWordMsg msg,void(*callBackFunc));

/***************************������д�(xml���ݸ�ʽ)*************************************/
extern "C"   __declspec(dllexport)bool checkBlackListXml(string url,SmsBlackListMsg msg,void(*callBackFunc));
/***************************������д�(JSON���ݸ�ʽ)*************************************/
extern "C"   __declspec(dllexport)bool checkBlackListJson(string url,SmsBlackListMsg msg,void(*callBackFunc));

/***********************************�ͷų����������Դ(�̲߳���ȫ,ֻ�������̵߳���)***************************/
extern "C"   __declspec(dllexport)void releaseLibrary();

