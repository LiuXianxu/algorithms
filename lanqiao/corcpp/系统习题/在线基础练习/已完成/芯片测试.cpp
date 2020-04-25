#include <stdio.h>
#define N 30
int a[N][N];
int main(){
	int n,i,j;
	int sum;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++){
		sum =0;
		for(j=0;j<n;j++)
		sum=sum+a[j][i];
		if(sum>n/2.0)
		printf("%d ",i+1);
	} 
	return 0;
}
