#include <stdio.h>
int main(){
	int dec,top=0;
	int stack[20];
	scanf("%d",&dec);
	if(!dec)printf("0");
	while(dec){
		stack[top++]=dec%8;
		dec/=8;
	}
	while(top){
		printf("%d",stack[--top]);
	}	
	return 0;
} 
