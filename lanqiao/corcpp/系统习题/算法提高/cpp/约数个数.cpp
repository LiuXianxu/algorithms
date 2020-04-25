#include <stdio.h>
int main(){
	int a,i,count=0;
	scanf("%d",&a);
	for(i=1;i<a+1;i++)
	if(a%i==0)count++;
	printf("%d",count);
	return 0; 
} 
