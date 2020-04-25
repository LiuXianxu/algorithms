#include <iostream>
using namespace std;
void S(int cnt,int n);
string s("0");
int main()
{
	int n;
	cin>>n;
	S(0,n);
	cout<<s<<endl;
	return 0;
}
void S(int cnt,int n)
{
	if(cnt==n)
		return ;
	string::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		if(*it=='0')
		{
			*it='1';
		}
		else if(*it=='1')
		{
			it=s.insert(it,'0');
			it++;
		}
	}
	S(cnt+1,n);
}
