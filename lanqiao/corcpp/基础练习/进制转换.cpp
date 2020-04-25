#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
string s;
int getNum(char ch);
int todec(string s);
int main()
{
	int dec;
	cin>>s;
	dec=todec(s);
	printf("%X %d %o",dec,dec,dec);	
	return 0;
}
int todec(string s)
{
	int len=s.length()-1;
	int i=len;
	int sum=0;
	while(i>=0)
	{
		sum = sum + getNum(s[i]) * pow(16,len-i);
		i--;
	}
	return sum;
}
int getNum(char ch)
{
	if(ch>='0'&&ch<='9')
		return ch-'0';
	else if(ch>='A'&&ch<='F')
		return ch-'A'+10;
}
