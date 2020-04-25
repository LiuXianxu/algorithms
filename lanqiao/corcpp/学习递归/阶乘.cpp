#include <stdio.h>
#define N 3000
int f[N]={0};
int main()
{
	int i,j,n;
	int c=0;
	f[0]=1;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		for(j=0;j<N;j++)
		{
			int s =f[j]*i+c;
			f[j]=s%10;
			c=s/10;
		}
	}
	for(j=0;j<N;j++)
	{
		if(f[j]!=0)
		{
			printf("%d",f[j]);
			break;
		}
	} 
	return 0;
} 
