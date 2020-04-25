#include <stdio.h>
int f(int dec); 
int main(){
	int n;
	scanf("%d",&n);
	printf("%d",f(n));
	
	return 0;
}
int f(int dec){
	
	if(dec==0)return 0;
	else return f(dec/2)+1;
	
}
