#include <stdio.h>
#define N 200
int a[N][N]; 
int main(){
	int i,j,m,n,sum;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	sum=n*m;
	i=-1;j=0;
	while(sum){
		//������ 
		while(a[++i][j]!=-1&&i<m)
		{
			printf("%d ",a[i][j]);
			a[i][j]=-1;
			sum--;
		}
		i--;
		//������ 
		while(a[i][++j]!=-1&&j<n){
			printf("%d ",a[i][j]);
			a[i][j]=-1;
			sum--;
		}
		j--;
		//������
		while(a[--i][j]!=-1&&i>=0){
			printf("%d ",a[i][j]);
			a[i][j]=-1;
			sum--;
		}
		i++;
		//������ 
		while(a[i][--j]!=-1&&j>=0){
			printf("%d ",a[i][j]);
			a[i][j]=-1;
			sum--;
		}
		j++;
	}
	return 0;
} 
