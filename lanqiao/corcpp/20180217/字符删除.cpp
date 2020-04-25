#include <iostream>
using namespace std;
int main()
{
	char ch;
	string str;
	int i;
	getline(cin,str);
	cin>>ch;
	string::iterator it;
	for(it=str.begin();it!=str.end();)
	{
		if(*it==ch)
		{
			it = str.erase(it);
		}
		else
		{
			it++;
		}
	}
	cout<<str; 
	return 0;
} 

