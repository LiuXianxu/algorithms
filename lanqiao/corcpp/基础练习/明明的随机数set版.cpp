#include <iostream>
#include <set>
using namespace std;
int main()
{
	set<int> s;
	int i,n,temp;	
	cin>>n;
	pair<set<int>::iterator,bool> insertPair;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		insertPair = s.insert(temp);
	}
	set<int>::iterator it;
	cout<<s.size()<<endl;
	for(it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<" ";
	}
	return 0;
} 
