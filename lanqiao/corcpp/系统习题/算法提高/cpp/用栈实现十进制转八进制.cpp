#include <stdio.h>
int main(){
	int a=0;
	int stack[50]={0},top=0;
	scanf("%d",&a);
	if(!a)printf("0");
	while(a){
		stack[top++]=a%8;
		a=a/8;
	}
	while(top){
		printf("%d",stack[--top]);
	}
	return 0; 
} 
