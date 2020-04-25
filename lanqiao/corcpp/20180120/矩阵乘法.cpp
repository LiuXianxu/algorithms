#include <stdio.h>
#define N 35
int c[N][N]={0};
void multiply(int a[][N],int c[][N],int n);
int main(){
	int a[N][N];
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	if(m)
	{	
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				c[i][j]=a[i][j];	
		for(i=0;i<m-1;i++)
			multiply(a,c,n);
	}
	else 
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(i==j)c[i][j]=1;	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",c[i][j]);
		printf("\n");		
	}
	return 0;
}
void multiply(int a[][N],int c[][N],int n)
{
	int b[N][N];
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			b[i][j]=c[i][j];
			c[i][j]=0;
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
			c[i][j]=c[i][j]+a[i][k] * b[k][j];
} 



