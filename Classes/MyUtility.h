#ifndef  _MY_UTILITY_H_
#define  _MY_UTILITY_H_

#include "cocos2d.h"

USING_NS_CC;

using namespace std;

//ͨ����
class MyUtility 
{
public:
	static string getCurrentTime();		//��õ�ǰ

	static string gbk_2_utf8(const string text);	//��win32��windows phone 8 ƽ̨�½�GBK�����ַ���ת��ΪUTF-8���룻

	static string getUTF8Char(const string key);	//���ļ� utf8_char.plist �а��ռ���ȡUTF-8�ַ�����

};

#endif // _MY_UTILITY_H_
