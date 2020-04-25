#include <stdio.h>
int main(){
	int a[5];
	for(a[0]=0;a[0]<2;a[0]++)
	for(a[1]=0;a[1]<2;a[1]++)
	for(a[2]=0;a[2]<2;a[2]++)
	for(a[3]=0;a[3]<2;a[3]++)
	for(a[4]=0;a[4]<2;a[4]++)
	printf("%d%d%d%d%d\n",a[0],a[1],a[2],a[3],a[4]);
	return 0;
}
