#include<iostream>
using namespace std;
int cnt = 0;
void f(int k,int n)
{
	if(k==n)
	{
		cnt++;
		return ;
	}
	if(k>n)
	{
		return ;
	}
	else
	{
		f(k+1,n);
		f(k+2,n); 
	} 
}
int main()
{
	int n;
	cin>>n;
	f(0,n);
	cout<<cnt;
} 
