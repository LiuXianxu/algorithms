#include <stdio.h>
#define N 105 
int data[N][N];
int max(int a,int b);
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			scanf("%d",&data[i][j]);
	for(i=n-2;i>=0;i--)
		for(j=0;j<=i;j++)
		data[i][j]=data[i][j]+max(data[i+1][j],data[i+1][j+1]);	
	printf("%d",data[0][0]);
	return 0;
} 

int max(int a,int b){
	return a>b?a:b;
} 


