#include <stdio.h>
void an(int n);
void sn(int n);
int main()
{
	an(1);
	printf("\n");
	an(3);
	printf("\n");
	sn(1);
	printf("\n");
	sn(3);
	return 0;
} 
void an(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("sin(%d",i);
		if(i!=n&&i%2)
		{
			printf("-");
		}
		if(i!=n&&i%2==0)
		{
			
			printf("+");
		}
		
	} 
	for(i=1;i<=n;i++)
	{
		printf(")");
	}
}
void sn(int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		printf("(");
	} 
	for(i=1;i<=n;i++)
	{
		an(i);
		printf("+%d",n-i+1);
		if(n-i)//666
		{
			printf(")");
		}	
	}
}
