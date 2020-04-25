#include<stdio.h>
#define N 20
int main(){
    int a[N],i,j,k,n,temp;
    scanf("%d",&temp);
    for(i=0;i<N&&temp!=0;i++)
    {
    	a[i]=temp;
    	scanf("%d",&temp);
    }
    n=i;
    for(i=0;i<2;i++)
    {
    	k=i;
    	for(j=i+1;j<n;j++)
    	if(a[j]>a[k])
		 k=j;
		temp=a[k];
		a[k]=a[i];
		a[i]=temp;
    }
    printf("%d",a[1]);
    return 0;
} 
