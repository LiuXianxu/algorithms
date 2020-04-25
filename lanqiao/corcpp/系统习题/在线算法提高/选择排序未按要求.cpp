#include <stdio.h>
int main(){
	int i,j,n,k,r,t,a[105];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(a[k]>a[j])
			k=j;
		t=a[i];
		a[i]=a[k];
		a[k]=t;
		printf("swap(a[%d], a[%d]):",i,k);
		for(r=0;r<n;r++)
		printf("%d ",a[r]);
		printf("\n"); 
		
	}
	return 0;
}
