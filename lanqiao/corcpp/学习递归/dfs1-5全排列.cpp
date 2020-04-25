#include <stdio.h>
int list[5];
int flag[5]={0};
void dfs(int n);
int main()
{
	dfs(0);
	return 0;
}
void dfs(int n)
{
	int i;
	if(n==5)
	{
		for(i=0;i<n;i++)
		{
			printf("%d ",list[i]);
		}
		printf("\n");
		return;
	}
	else
	{
		for(i=0;i<5;i++)
		{
			if(flag[i]==0)
			{
				flag[i]=1;
				list[n]=i+1;
				dfs(n+1);
				flag[i]=0;
			}
		}
	} 
}
