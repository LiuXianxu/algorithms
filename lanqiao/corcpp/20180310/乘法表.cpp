#include <stdio.h>
int main()
{
	int i,j;
	for(i=1;i<10;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=%d",i,j,i*j);
			if(j==i)
			{
				printf("\n");
			}
			else
			{
				printf(" ");
			}
		}
	}
	
	return 0;
} 
