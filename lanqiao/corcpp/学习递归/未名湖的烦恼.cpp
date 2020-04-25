#include <stdio.h>
int num(int m,int n);
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	printf("%d",num(m,n)); 
	return 0;
} 
int num(int m,int n)
{
	if(m<n)
		return 0;
	else if(n==0)
		return 1;
	else return num(m-1,n)+num(m,n-1);	
}
