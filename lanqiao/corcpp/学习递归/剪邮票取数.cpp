#include <stdio.h>
int is[15]={0};
int p[15]={0};
int yp[15];
void dfs(int a); 
int main(){
	int i;
	for(i=0;i<12;i++)
	{
		yp[i]=i+1;
	}
	dfs(1); 
				//n=11*9*8;
	return 0;
} 
void dfs(int a)
{
	int i,j;
	if(a==6)
	{
		for(i=1;i<=5;i++)
		printf("%d ",p[i]);
		printf("\n");
		return ;
	}
	else 
	{
		for(i=p[a-1]+1;i<=12;i++)
		{
			if(is[i]==0)
			{
				is[i]=1;
				p[a] = i;
				dfs(a+1);
				is[i]=0;
			}
		
		}
	}
}


