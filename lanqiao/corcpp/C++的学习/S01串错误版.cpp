#include <iostream>
#include <string.h>
using namespace std;
char str[1000]={'\0'};
void String01(int cnt,int n); 
int main()
{
	int n;
	cin>>n;
	str[0]='0';
	String01(0,n);
	cout<<str;
	return 0;
} 
void String01(int cnt,int n)
{
	if(cnt==n)return;
	int i,j;
	int len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]=='0')
		{
			str[i]='1';
		}
		else if(str[i]=='1')
		{
			for(j=len;j>i;j--)
			{
				str[j]=str[j-1];
			}
			str[i]='0';
		}
	}
	String01(cnt+1,n);
}
