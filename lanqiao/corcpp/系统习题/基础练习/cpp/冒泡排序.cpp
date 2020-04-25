#include <stdio.h>
#include <stdlib.h> 
int main(){
	int i,j,n,*a,t;
	scanf("%d",&n);
	getchar();
	a= (int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%-2d",a[i]);
	}
	return 0;
} 
