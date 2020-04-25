#include <stdio.h>
#include <math.h>
char str[9];
int ToNum(char ch){

	if(ch>='0'&&ch<='9')
		return ch-'0';
	else if(ch>='A'&&ch<='F')
		return ch-55;
}
int main(){
	long long n=0;
	int i,len=-1;
	scanf("%s",str);
	while(str[++len]);	
	for(i=len-1;i>=0;i--)
	{
		n=n+ToNum(str[i])*pow(16,len-i-1);
	}
	printf("%I64d",n);
	return 0;
} 
