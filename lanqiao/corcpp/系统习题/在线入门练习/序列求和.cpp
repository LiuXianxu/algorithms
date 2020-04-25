#include <stdio.h>
int main(){
	long long sum=0; 
	int n,i;
	scanf("%d",&n);
	sum = (long long)n*(n+1)/2;	
	printf("%I64d",sum);
	return 0;
}
