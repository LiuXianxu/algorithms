#include <stdio.h>
#include <stdlib.h>
void dynamic(int n);
int main(){

	int n,i;
	scanf("%d",&n);
	dynamic(n);	
	return 0;
}
void dynamic(int n){
	int *a=NULL;
	int sum=0,i;
	a=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	for(i=0;i<n;i++)
		sum=sum+*(a+i);
	printf("%d %d",sum,sum/n);
	free(a);
}
