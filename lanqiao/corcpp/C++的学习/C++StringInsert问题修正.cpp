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
//	s[2]='2';  用数组下标的方式赋值会使insert()函数无法插入 
	s.insert(1,p); 
	cout<<s;
	return 0;
}
