#include <iostream>
#include <vector> 
#include <map>
#include <cctype>
#include <algorithm>
#include <cstdio>
using namespace std;
void f();
string repr(const string &s);
int main()
{
	f();
	return 0;
}
void f()
{
	map<string,int> m;
	vector<string> words;
	string str,rs;
	freopen("C:\\Users\\ÎÒµÄµçÄÔ\\Desktop\\in.txt","r",stdin);
	while(cin>>str)
	{
		if(str[0]=='#')
			break;
		else 
		words.push_back(str);
	}
	vector<string>::iterator it;
	for(it=words.begin();it!=words.end();it++)
	{
		rs=repr(*it);
		pair<map<string,int>::iterator,bool> insertPair;
		insertPair = m.insert(pair<string,int>(rs,1));
		if(insertPair.second==false)
			m[rs]++;	//m.at(rs)++;
	}
	map<string,int>::iterator itm;
	pair<string,int> p;
	for(it=words.begin();it!=words.end();it++)
	{
		rs=repr(*it);
		for(itm=m.begin();itm!=m.end();itm++)
		{
			p=(pair<string,int>)*itm;
			if(rs.compare(p.first)==0&&p.second==1)
			cout<<*it<<endl;
		}
		
	}
	
	
}
string repr(const string &s)
{
	string ans = s;
	int i;
	for(i=0;i<s.length();i++)
	{
		ans[i]=tolower(ans[i]);
	}
	sort(ans.begin(),ans.end());
	return ans;
}
