#include <stdio.h>
char str[100];
int top=0;
int main()
{
/*	scanf("%d",&str[top++]);
	while(str[top-1]!='*')
	{
		scanf("%d",&str[top++]);
	}
*/
	do
	{
		scanf("%c",&str[top++]);	
	}while(str[top-1]!='*');
	
	
	
	//printf("%s",str); 
	return 0;
} 
