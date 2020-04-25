#include <iostream>
using namespace std;
int getCh(string str); 
int main()
{
	string str;
	cin>>str;
	cout<<getCh(str);
	return 0;
} 
int getCh(string str)
{
	int len = str.length();
	for(int i=0;i<len;i++)
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
		{
			return i+1;
		}
	}
	return 0;
}
