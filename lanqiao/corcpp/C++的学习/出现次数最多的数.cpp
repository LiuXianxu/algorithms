#include <cstdio>
#include <iostream>
#include <map>
const int N=20;
int a[N];
using namespace std; 
int main(){
	map<int,int> m;
	pair<map<int,int>::iterator,bool> InsertPair;
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(n>0)
	{
		for(i=0;i<n;i++)
		{
			InsertPair=m.insert(pair<int,int>(a[i],1));
				if(InsertPair.second==false)
			m[a[i]]++;	//m.at(a[i])++; 
		}
		map<int,int>::iterator it;
		pair<int,int> q,max;
		it=m.begin();
		max=(pair<int,int>)*it;
		for(it=m.begin();it!=m.end();it++)
		{
			q=(pair<int,int>)*it;
			if(max.second<q.second)
			max=q;
		}
		cout<<max.first;
	}
	return 0;
}
