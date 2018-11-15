#include "windows.h"
#include<string>
using namespace std;
char* UTF8toUnicode(const char* utf, size_t *unicode_number);
char* UnicodetoUTF8(const char* unicode);
string UTF8ToGBK(const std::string& strUTF8) ;