#include <stdio.h>
char hex[20]={'\0'};
char tohex(int n){
	switch(n){
		case 15: return 'F';
		case 14: return 'E';
		case 13: return 'D';
		case 12: return 'C';
		case 11: return 'B';
		case 10: return 'A';
		default:return  n+48;//ASCIIÂëÓ¦ÓÃ; 
	}
}
int main(){
	int a,i=0;
	int top=0;
	scanf("%d",&a);
	if(a==0)printf("%d",a);
	else{
	while(a){
		hex[top++]=tohex(a%16);
		a/=16;
	}
	for(i=top-1;i>=0;i--){
		printf("%c",hex[i]);
	}
	}
	return 0;
} 
