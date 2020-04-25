#include <stdio.h>
#define N 1000
long long a[N][N];
long long b[N][N];
long long c[N][N]={0};
void multiply(long long a[][N],long long b[][N],long long c[][N],int ai,int ab,int bj); 
int main()
{
	int ai,aj,bi,bj;
	int i,j;
	scanf("%d%d",&ai,&aj);
	for(i=0;i<ai;i++)
		for(j=0;j<aj;j++)
		{
			scanf("%I64d",&a[i][j]);
		} 
	scanf("%d%d",&bi,&bj);
	for(i=0;i<bi;i++)
		for(j=0;j<bj;j++)
		{
			scanf("%I64d",&b[i][j]);
		}
	multiply(a,b,c,ai,aj,bj);
	for(i=0;i<ai;i++)
	{
		for(j=0;j<bj;j++)
			printf("%I64d ",c[i][j]);
		printf("\n");
	}
	return 0;
}
void multiply(long long a[][N],long long b[][N],long long c[][N],int ai,int ab,int bj)
{
	int i,j,k;
	for(i=0;i<ai;i++)
		for(j=0;j<bj;j++)
		{
			for(k=0;k<ab;k++)
			c[i][j]=c[i][j]+a[i][k]*b[k][j];
		}
}
