#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	int n;
	string str;
	cin>>n>>str;
	
	return 0;
} 
int cnt(string str,int n)
{
	map<string,int> m;
	int i;
	string s;
	pair<map<string,int>::iterator,bool> insertPair;
	for(i=0;i<str.length();i++)
	{
		s=str.substr(i,i+n);
		insertPair = m.insert(pair<string,int>(s,1));
		if(insertPair.second==false)
		m[s]++;
	}
}
