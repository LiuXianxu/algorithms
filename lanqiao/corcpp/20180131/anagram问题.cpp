#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;
string reverse(const string s);
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	s1=reverse(s1);
	s2=reverse(s2);
	if(s1.compare(s2)==0)
	{
		cout<<"Y";
	}
	else 
	{
		cout<<"N";
	}
	return 0;
} 
string reverse(const string s)
{
	int i;
	string s1=s;
	for(i=0;i<s1.length();i++)
	{
		s1[i]=tolower(s1[i]);
	}
	sort(s1.begin(),s1.end());
	return s1;
}
