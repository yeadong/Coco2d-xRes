2014-03-21
每次调用的时候要写很长的代码。可以建议搞几个宏，毕竟CCUserDefault的get，set实在太长了。
#define SaveStringToXML CCUserDefault::sharedUserDefault()->setStringForKey  
  
#define SaveIntegerToXML CCUserDefault::sharedUserDefault()->setIntegerForKey  
  
#define SaveBooleanToXML CCUserDefault::sharedUserDefault()->setBoolForKey  
  
#define LoadStringFromXML CCUserDefault::sharedUserDefault()->getStringForKey  
  
#define LoadIntegerFromXML CCUserDefault::sharedUserDefault()->getIntegerForKey  
  
#define LoadBooleanFromXML CCUserDefault::sharedUserDefault()->getBoolForKey 

如何首次生成判断文件是否存在呢
其实可以利用get方法去获取。 
[cpp] view plaincopy
if ( !LoadBooleanFromXML("_IS_EXISTED"))   
  
{  
  
       initUserData();               
  
       SaveBooleanToXML("_IS_EXISTED", true);  
  
} 