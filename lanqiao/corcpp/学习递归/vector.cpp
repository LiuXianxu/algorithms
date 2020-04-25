#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int i;
	vector<int> v1(10);
	for(i=0;i<10;i++)
	{
		v1[i]=i;
	}
	v1.push_back(100);
	v1.insert(v1.begin(),123);
	cout<<v1.size()<<endl;
	cout<<v1.capacity()<<endl;
	cout<<v1.at(10)<<endl;
	cout<<v1.front()<<endl;
	cout<<v1.back()<<endl;
	for(i=0;i<12;i++)
	{
		cout<<v1[i]<<" ";
	}
	cout<<endl;
	vector<int>::iterator it;
	for(it=v1.begin();it!=v1.end();it++)
	{
		*it=0;
		cout<<*it<<" ";
	}
	cout<<endl;
	for(i=0;i!=2;i++)
		cout<<i<<" ";
	return 0;
} 
