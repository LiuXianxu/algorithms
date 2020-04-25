#include <stdio.h>
int a[1001];
int main(){
	int i,n,m,flag=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(i=0;i<n;i++){
		if(m==a[i]){ 
			printf("%d",i+1);
			flag=0;
			break; 
		} 
	}
	if(flag)printf("%d",-1);
	return 0;
} 
