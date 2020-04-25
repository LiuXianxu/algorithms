#include <stdio.h>
int s[5];
char flag[5]={'\0'};
void dfs(int n);
int main()
{
	dfs(1);
	return 0;
}
void dfs(int n)
{
	int i;
	if(n==4)
	{
		printf("\n");
		for(i=0;i<3;i++)
			printf("%d",s[i]);
		printf("\n");
		return ;	
	}
	else 
	{
		for(i=0;i<3;i++)
		{
			if(flag[i]=='\0')
			{	
				flag[i]='1';
				s[n-1]=i;
				printf("%d ",n);
				dfs(n+1);
				printf("»ØËÝÖÐ£ºn=%d\n",n);
				flag[i]='\0';
			}
		}
	}
} 
