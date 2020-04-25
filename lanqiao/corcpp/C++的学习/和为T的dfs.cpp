#include <iostream>
using namespace std;
int sum = 0;
int n = 0;
int l = 0;
int cnt = 0;
int a[25];
int b[25];
void reverse(int a[],int n);
void f(int k,int z); 
int main()
{
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>sum;
	reverse(a,n);
	f(0,0);
	cout<<cnt;
	return 0;
}
void f(int k,int z)
{
	if(k==n)
	{
		if(z==sum&&l!=0)
		{
			for(int i=l-1;i>=0;i--)
			{
				cout<<b[i]<<" ";
			}
			cnt++;
			cout<<endl;
		}
		return ;
	}
	f(k+1,z);
	b[l++]=a[k];
	f(k+1,z+a[k]);
	l--;
}
void reverse(int a[],int n)
{
	int i,t;
	for(i=0;i<n/2;i++)
	{
		t = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] = t;
	}
}
