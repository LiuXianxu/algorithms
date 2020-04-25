#include <stdio.h>
int a[100][2];
int b[100]={0};
int main(){
	int i,j,k,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		b[i]=a[i][0]+a[i][1];
	for(i=0;i<2;i++)
	{			
		k=i;
		for(j=i+1;j<n;j++)
		if(b[j]>b[k])k=j;
		int t=b[k];
		b[k]=b[i];
		b[i]=t;
	}
	if(b[0]>=0&&b[1]>=0)
	printf("%d",b[0]+b[1]);
	else
	printf("0");
	return 0;
} 
