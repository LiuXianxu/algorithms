#include <iostream>
#include <set>
//#include <algorithm>
using namespace std;
set<int> s;
int dn(int n);
void insertSet(int n);
int main()
{
	int i,n;
	cin>>n;
	insertSet(n);
	pair<set<int>::iterator,bool> insertPair;
	for(i=1;i<n;i++)
	{
		insertPair = s.insert(i);
		if(insertPair.second==true)
		{
			cout<<i<<endl;
		}
	}
	return 0;
} 
void insertSet(int n)
{
	int i;
	int e;
	pair<set<int>::iterator,bool> insertPair;
	for(i=1;i<n;i++)
	{
		insertPair = s.insert(dn(i));
	}
}
int dn(int n)
{
	int sum=n;
	do
	{
		sum=sum+n%10;
		n/=10;
	}while(n>0);
	return sum;
}
