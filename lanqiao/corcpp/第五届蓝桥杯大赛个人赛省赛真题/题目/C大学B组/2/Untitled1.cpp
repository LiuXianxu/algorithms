#include <stdio.h>
int main(){
	int i;
	float sum=0;
	for(i=1;i<10000000;i++)
	{
	sum=sum+(float)1/i;
	if(sum>=15.0){
	printf("%d\n",i);
	break;
	}
	}
	printf("%f",sum);
	return 0;
}
