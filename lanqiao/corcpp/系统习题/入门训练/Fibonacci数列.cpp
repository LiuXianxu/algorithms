#include <stdio.h>
#define MOD 10007
#define MAXN 1000001
int f[MAXN];
int main(){
	int n,i;
	f[1]=1;
	f[2]=1;
	scanf("%d",&n);
	for(i=3;i<=n;i++){
		f[i]=(f[i-1]+f[i-2]) % MOD;
	}
	printf("%d",f[n]);
	return 0;
} 
