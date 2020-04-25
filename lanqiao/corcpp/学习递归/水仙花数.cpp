#include <stdio.h>
void f(int n);
int main()
{
	int n;
	scanf("%d",&n);
	f(n);
	return 0;
}
void f(int n)
{
	int a,b,c;
	a=n/100;
	b=n%100/10;
	c=n%10;
	if(n==a*a*a+b*b*b+c*c*c)
	{
		printf("YES");
	}
	else 
	{
		printf("NO");
	}
	
}
