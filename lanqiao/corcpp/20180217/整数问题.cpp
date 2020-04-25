#include <iostream>
using namespace std;
int main()
{
	int min,max,factor;
	cin>>min>>max>>factor;
	for(int i=min;i<=max;i++)
	{
		if(i%factor==0)
		{
			cout<<i<<" ";
		}
	}
	return 0;
}
