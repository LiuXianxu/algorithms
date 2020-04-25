#include <stdio.h>
#define N 40
void cf(int t[][N],int s[][N],int n);
int main(){
	int n,m,i,j;
	int a[N][N],s[N][N]={0};
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}

	for(i=0;i<m-1;i++)
		cf(a,s,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
			printf("%d ",s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void cf(int t[][N],int s[][N],int n)
{
	int i,j,k;
	int a[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			a[i][j]=t[i][j];
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			
			for(k=0;k<n;k++)
				s[i][j]=s[i][j]+a[i][n-1-k]*t[n-1-k][j];
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			t[i][j]=s[i][j];
		}
}
