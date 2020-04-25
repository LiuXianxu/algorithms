#include <stdio.h>
#define T 1005
#define N 20
int a[T][N];
int n[T];
int sum[T]={0};
int main()
{
	int i,j,k,m,temp;
	int t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n[i]);
		for(j=0;j<n[i]*2;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<t;i++)
	{
		for(j=0;j<n[i]-1;j++)
		{
			m=j;
			for(k=j+1;k<n[i];k++)
				if(a[i][k]>a[i][m])
					m=k;
			temp=a[i][j];
			a[i][j]=a[i][m];
			a[i][m]=temp;
		}
		for(j=n[i];j<2*n[i]-1;j++)
		{
			m=j;
			for(k=j+1;k<2*n[i];k++)
				if(a[i][k]<a[i][m])
					m=k;
			temp=a[i][j];
			a[i][j]=a[i][m];
			a[i][m]=temp;

		}
		for(j=0;j<n[i];j++)
		{
			sum[i]=sum[i]+a[i][j]*a[i][j+n[i]];
		}
	}
	for(i=0;i<t;i++)
		printf("%d\n",sum[i]);

	return 0;
}