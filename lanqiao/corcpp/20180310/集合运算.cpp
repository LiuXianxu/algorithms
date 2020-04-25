#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n,m;
	int i,t;
	cin>>n;
	set<int> s1,s2;
	for(i=0;i<n;i++)
	{
		cin>>t;
		s1.insert(t);
	}
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>t;
		s2.insert(t);
	}
	set<int>::iterator it;
	pair<set<int>::iterator,bool> insertPair;
	set<int> intersection,subtractSet;
	for(it=s1.begin();it!=s1.end();it++)
	{
		insertPair = s2.insert(*it);
		if(insertPair.second == false)
		{
			intersection.insert(*it);
		}
		else
		{
			subtractSet.insert(*it);
		}
	}
	if(intersection.empty()==false)
	{
		for(it=intersection.begin();it!=intersection.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	if(s2.empty()==false)
	{
		for(it=s2.begin();it!=s2.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	if(subtractSet.empty()==false)
	{
		for(it=subtractSet.begin();it!=subtractSet.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	return 0;
}

