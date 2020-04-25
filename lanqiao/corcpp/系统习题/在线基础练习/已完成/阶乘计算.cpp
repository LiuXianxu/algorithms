#include <stdio.h>
#define N 3000
int A[N]={0};
int main(){
	int i,j,n,c=0;
	scanf("%d",&n);
	A[0]=1;
	for(i=2;i<=n;i++)
	{
		for(j=0;j<N;j++)
		{
			int s=A[j]*i+c;
			A[j]=s%10;
			c=s/10;
		}
	}
	for(j=N;j>=0;j--)
	if(A[j])break;
	for(i=j;i>=0;i--)
	printf("%d",A[i]);
	printf("\n");
	return 0;
} 
