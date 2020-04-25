#include <Stdio.h>
int f(int k,int n){
	if(k==0||k==n)return 1;
	else return f(k,n-1)+f(k-1,n-1);
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",f(a,b)); 
	return 0;
}
