#include<stdio.h>
int a[100];
int N,K;
long long b[100][100]={0};
long long g(int top,int end)
{
	int i;
	long long q=0;
	for(i=top;i<=end;i++)
    	q+=a[i];
	return q;
}
long long f(int begin,int k)
{
	int i;
	long long t,ans=0;
	if(b[begin][k])return b[begin][k];
	if(k==0)
    	return g(begin,N-1);
	if(begin==N-1&&k)  //不是很懂，乘法返回0？ 
    	return 0;
	for(i=begin+1;i<=N-1;i++){
    	if(ans<(t=(g(begin,i-1)*f(i,k-1)))){
        	ans=t;
    	}
	}
	return b[begin][k]=ans;
}
int main()
{
	int i;
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++){
    	scanf("%d",&a[i]);
	}
	printf("%lld\n",f(0,K));
	return 0;
}

