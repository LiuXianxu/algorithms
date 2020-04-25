#include <stdio.h>
#define N 50
int f[N];
int main(){
	unsigned long long sum=0; 
	long n,i;
	f[0]=0;
	scanf("%d",&n);
/*	for(i=1;i<=n;i++){
		sum = sum +i;
	}
*/
	sum = (long long)n*(n+1)/2;	
	printf("%I64d",sum);
	return 0;
}
