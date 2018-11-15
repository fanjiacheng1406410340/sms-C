1.bin 目录是可执行短信接口调用示例和程序调用接口所需的动态链接库
libcurl.dll(必须)
libeay32.dll(必须)
libidn-11.dll(必须)
librtmp.dll(必须)
ssleay32.dll（必须）
zlib1.dll（必须）
libssh2.dll(发送https协议一来动态链接库,目前接口不支持)
msvcp110d.dll(vc++2012程序运行所依赖的库，如windows操作系统已有,可以去掉)
msvcr110d.dll（vc++2012程序运行所依赖的库，如windows操作系统已有,可以去掉）
Sms.dll（发送短信接口动态链接库(支持短信下行,获取状态报告,短信上行,余额查询,黑名单检测,敏感词检测),支持xml和json数据格式）
2.include目录 
使用短信sdk开发所包含的头文件,工程包含即可
3.lib目录
使用隐式加载动态链接库所需的lib库
4.src
sdk和调用sdk源码
