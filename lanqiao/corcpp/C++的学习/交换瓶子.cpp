#include <iostream>
using namespace std;
const int N=10005;
int a[N];
int main()
{
	int cnt=0;
	int i,j,n;
	int k,temp;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[k]>a[j])
			{
				k=j;
			}
		}
		if(i!=k)
		{
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
} 
/*
	Êä³ö£º
	cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
*/
