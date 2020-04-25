#include <iostream>
using namespace std;
int main()
{
	string s;
	s="01010";
	cout<<s<<endl;
	string::iterator i,start,stop;
	start=s.begin();
	stop=s.end();
	for(i=s.begin();i!=s.end();i++)
	{
		if(*i=='1')
		{
			i=s.insert(i,'0');
			i++;
		}
	}
	cout<<s<<endl;
	return 0;
} 
