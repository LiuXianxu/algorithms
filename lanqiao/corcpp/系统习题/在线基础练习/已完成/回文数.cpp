#include <stdio.h>
int main(){
	int a[2]={0};
	for(a[0]=1;a[0]<10;a[0]++)
	for(a[1]=0;a[1]<10;a[1]++)
	printf("%d%d%d%d\n",a[0],a[1],a[1],a[0]);
	return 0;
}
