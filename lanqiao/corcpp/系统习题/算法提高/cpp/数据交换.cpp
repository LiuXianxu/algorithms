#include<stdio.h>
#define N 20
int main(){
	int a[N],t,i,count=-1;
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[++count]);
		if(a[i]==0)break;
		
	}
	for(i=0;i<count/2;i++)
	{
		t=a[i];
		a[i]=a[count-1-i];
		a[count-1-i]=t;
	}
	for(i=0;i<count;i++){
		printf("%d ",a[i]);
	}
	return 0;
} 
