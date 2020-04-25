#include <Stdio.h>
int main(){
	int t,a,b,c;
	scanf("%d",&t);
	a=t/3600;
	b=t%3600/60;
	c=t%3600%60;
	printf("%d:%d:%d",a,b,c);
	return 0;
}
