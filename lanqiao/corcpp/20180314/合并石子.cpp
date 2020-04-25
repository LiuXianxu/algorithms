#include <stdio.h>
#include <iostream>
#include <string.h>
#define inf 0x3f3f3f3f
using namespace std;
int dp[1001][1001];
int a[1010]={0},s[1010][1010];
int main()
{
	memset(dp,inf,sizeof(dp));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		dp[i][i]=0;
		a[i] += a[i-1];
		s[i][i] = i;
	}
	int temp;
	for(int len =2;len<=n;len++)
	{
		for(int i=1,j=len;j<=n;i++,j++)
		{
			for(int k=s[i][j-1];k<=s[i+1][j];k++)
			{
				temp =dp[i][k] +dp[k+1][j]+a[j]-a[i-1];
				if(temp<dp[i][j])
				{
					dp[i][j]=temp;
					s[i][j]=k;
				}
			}
		}
	}
	printf("%d",dp[1][n]);
	return 0;
}
