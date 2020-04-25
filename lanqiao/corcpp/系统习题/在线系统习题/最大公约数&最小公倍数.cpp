#include <stdio.h>
int lcm(int a,int b){
	int t=0,x1=a,x2=b;
	while(x1%x2!=0){
		t=x1%x2;
		x1=x2;
		x2=t;
	}
	return a*b/x2;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",lcm(a,b));
	return 0;
} 
