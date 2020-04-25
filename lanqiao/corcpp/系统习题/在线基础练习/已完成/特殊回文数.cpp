#include <stdio.h>
int main(){
	int n,a[3]={0};
	scanf("%d",&n);
	for(a[0]=1;a[0]<=9;a[0]++)
		for(a[1]=0;a[1]<=9;a[1]++)
			for(a[2]=0;a[2]<=9;a[2]++)
				if(2*(a[0]+a[1])+a[2]==n)
					printf("%d%d%d%d%d\n",a[0],a[1],a[2],a[1],a[0]);
	for(a[0]=1;a[0]<=9;a[0]++)
		for(a[1]=0;a[1]<=9;a[1]++)
			for(a[2]=0;a[2]<=9;a[2]++)
				if(2*(a[0]+a[1]+a[2])==n)
					printf("%d%d%d%d%d%d\n",a[0],a[1],a[2],a[2],a[1],a[0]);
	return 0;
}
