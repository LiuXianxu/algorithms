#include <iostream>
using namespace std;
int main()
{
	int cnt=0;
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
