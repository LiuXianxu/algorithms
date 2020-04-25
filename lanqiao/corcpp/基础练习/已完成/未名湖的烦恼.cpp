#include<stdio.h>
#include<string.h>
int f[20][20]; 
int main(){
	int i,j,m,n;
	memset(f,0,sizeof(f));
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
	f[i][0]=1;
	for(j=1;j<=n;j++)
	f[0][j]=1;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(i==j)
			f[i][j]=f[i][j-1];
			else if(i>j)
			f[i][j]=f[i][j-1]+f[i-1][j];
		}
		
	printf("%d\n",f[m][n]);
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
			printf("%d ",f[i][j]);
		printf("\n");
	}
	return 0;
} 
