#include <stdio.h>
int tonum(char ch);
int power(int x,int y);
int main(){
	int i,top=0,t=0;
	int dec=0,oct[5];
	char str[5];
	scanf("%s",str);
	printf("Hex: 0x%s\n",str);
	for(i=2;i>=0;i--)
	{
		dec=dec+tonum(str[i])*power(16,2-i);
	}
	printf("Decimal: %d\n",dec);
	while(dec){
		oct[top++]=dec%8;
		dec/=8;
	}
	while(top){
		t=t+oct[--top]*power(10,top);
	}
	printf("Octal: %04d\n",t);
	return 0;
} 
int tonum(char ch){
	if(ch>='0'&&ch<='9')
	return ch-'0';
	else
	return ch-55;	
} 
int power(int x,int y){
	int i=0,z=1;
	if(y==0)return 1;
	else
	 for(i=0;i<y;i++)
	{
		z=z*x;
	}
	return z;
}
