#include <stdio.h>
int main(){
	int a,b,t;
	scanf("%d%d",&a,&b);
	while(a%b!=0){
		t=a%b;
		a=b;
		b=t;
	}
	printf("%d",b);
	return 0; 
} 
