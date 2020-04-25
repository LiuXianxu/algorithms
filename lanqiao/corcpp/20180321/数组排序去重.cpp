#include <iostream>
#include <set>
using namespace std;
const int N=10;
int main()
{
	int temp;
	set<int> s;
	for(int i=0;i<N;i++)
	{
		cin>>temp;
		s.insert(temp);
	}
	set<int>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<endl;
	}
	return 0;
} 
