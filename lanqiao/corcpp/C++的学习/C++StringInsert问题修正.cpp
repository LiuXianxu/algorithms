#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	char *p;
	char ch;
	ch='2';
	p=&ch;
	string s("012"); 
//	s[0]='0';
//	s[1]='1';
//	s[2]='2';  �������±�ķ�ʽ��ֵ��ʹinsert()�����޷����� 
	s.insert(1,p); 
	cout<<s;
	return 0;
}
