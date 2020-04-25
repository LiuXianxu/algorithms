#include <stdio.h>
#define N 8
int a[N][N]={0};
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	
	return 0;
}
int queen(int n){
	
	
} 
int place(int k,int num)
{
	int i,j,m,n;
	int flag=1;
	for(i=0;i<k;i++)
	for(j=0;j<k;j++)
	{
		if(a[i][j]==1)
		{
			for(m=i;m<num;m++)
			if(a[m][j]==2||a[m][j]==4)
				flag=0;
			for(n=j;n<num;n++)
			if(a[i][n]==2||a[i][n]==4)
				flag=0;
			for(m=i,n=j;i<num&&j<num;i++,j++)
			if(a[m][n]==2||a[m][n]==4)
				flag=0;
		}
		
	}
	
}
