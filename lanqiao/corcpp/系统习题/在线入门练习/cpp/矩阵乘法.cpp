#include <stdio.h>
#define N 205
int a[N][N],b[N][N],c[N][N]={0};
int main()
{
	int m,s,n;
	int i,j,k;
	scanf("%d%d%d",&m,&s,&n);
	for(i=0;i<m;i++)
		for(j=0;j<s;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<s;i++)
		for(j=0;j<n;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			for(k=0;k<s;k++)
				c[i][j]=c[i][j]+a[i][k]*b[k][j];

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	return 0;

}