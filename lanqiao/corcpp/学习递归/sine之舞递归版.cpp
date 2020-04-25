#include <stdio.h>
void an(int n,int t);
void sn(int n,int t);
int main()
{
	int n;
	scanf("%d",&n);
	sn(n,1);
	if(n!=1)
	printf(")");
	an(n,1);
	printf("+1\n");
	return 0;
} 
void an(int n,int t)
{
	 if(n==t)
	 {
	 	printf("sin(%d)",t);
	 	return ;
	 }
	 char c;
	 c=t%2==1?'-':'+';
	 printf("sin(%d%c",t,c);
	 an(n,t+1);
	 printf(")");
	 
}
void sn(int n,int t)
{
	if(n==t)
	{
		return;
	}
	printf("(");
	sn(n,t+1);
	if(t!=n-1)
	{
		printf(")");
	}
	an(n-t,1);
	printf("+%d",t+1);
}
