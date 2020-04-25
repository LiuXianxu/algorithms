#include <iostream>
using namespace std;
long long flag[20][20]={0};
long long a[20];
int N,K;
long long continuousadd(int begin,int end)
{
	long long sum=0;
	int i=begin;
	for(i=begin;i<=end;i++)
	{
		sum+=a[i];
	}
	return sum;
}
long long continuousmultiply(int head,int num)
{
	int i;
	long long t,ans=0;
	if(flag[head][num])return flag[head][num];
	if(num==0)
	return continuousadd(head,N-1);
	if(head==N-1&&num)
	return 0;
	for(i=head+1;i<N;i++)
	{
		t=continuousadd(head,i-1)*continuousmultiply(i,num-1);
		if(ans<t)
		{
			ans=t;
		}
	}
	return flag[head][num]=ans;
}
int main()
{
	int i;
	cin>>N>>K;
	for(i=0;i<N;i++)
	{
		cin>>a[i];
	}
	cout<<continuousmultiply(0,K);
	return 0;
}

