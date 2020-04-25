#include <stdio.h>
int a[10001];
int main(){
	int max,min,i,j,k,n,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=min=a[0];
	for(i=1;i<n;i++)
	if(max<a[i])
		max=a[i];
	printf("%d\n",max);
	for(i=1;i<n;i++)
	if(min>a[i])
		min=a[i];
	printf("%d\n",min);
	for(i=0;i<n;i++)
		sum=sum+a[i];
	printf("%d\n",sum);
	return 0;
}
