#include <stdio.h>
int a[50][50]={0};
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i][0]=1;
		printf("%d ",a[i][0]);
		for(j=1;j<=i;j++)
		printf("%d ",a[i][j]=a[i-1][j]+a[i-1][j-1]);
		printf("\n");
	}
	return 0;
} 
