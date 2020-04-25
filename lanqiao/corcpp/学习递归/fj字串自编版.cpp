#include <stdio.h>
void fj(int n);
int main()
{
	int n;
	scanf("%d",&n); 
	fj(n);
	return 0;
}
void fj(int n)
{
	if(n==1)
	{
		printf("%c",'A');
		return ;
	}
	else 
	{
		fj(n-1);
		printf("%c",'A'+n-1);
		fj(n-1);
	}
}
