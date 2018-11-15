#include"stdafx.h"
#include"encrypt.h"

char* UTF8toUnicode(const char* utf, size_t *unicode_number)
{
	if(!utf || !strlen(utf))
	{
		*unicode_number = 0;
		return NULL;
	}
	int dwUnicodeLen = MultiByteToWideChar(CP_UTF8,0,utf,-1,NULL,0);
	size_t num = dwUnicodeLen*sizeof(wchar_t);
	wchar_t *pwText = (wchar_t*)malloc(num);
	memset(pwText,0,num);
	MultiByteToWideChar(CP_UTF8,0,utf,-1,pwText,dwUnicodeLen);
	*unicode_number = dwUnicodeLen - 1;
	return (char*)pwText;
}

char* UnicodetoUTF8(const char* unicode)
{
	int len;
	len = WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)unicode, -1, NULL, 0, NULL, NULL);
	char *szUtf8 = (char*)malloc(len + 1);
	memset(szUtf8, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, (const wchar_t*)unicode, -1, szUtf8, len, NULL,NULL);
	return szUtf8;
}

string UTF8ToGBK(const std::string& strUTF8) 
{ 
 int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8.c_str(), -1, NULL, 0);
 unsigned short * wszGBK = new unsigned short[len + 1]; memset(wszGBK, 0, len * 2 + 2); 
 MultiByteToWideChar(CP_UTF8, 0, (LPCCH)strUTF8.c_str(), -1, (LPWSTR)wszGBK, len);
 len = WideCharToMultiByte(CP_ACP, 0, (LPCWCH)wszGBK, -1, NULL, 0, NULL, NULL); 
 char *szGBK = new char[len + 1];
 memset(szGBK, 0, len + 1); 
 WideCharToMultiByte(CP_ACP,0, (LPCWCH)wszGBK, -1, szGBK, len, NULL, NULL); //strUTF8 = szGBK; 
 std::string strTemp(szGBK); 
 delete[]szGBK; 
 delete[]wszGBK; 
 return strTemp; 
}

