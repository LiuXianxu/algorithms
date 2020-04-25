#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max;
void fun(int *val,int index,int size,int m,int cnt,int res);
int main()
{
	int n,m,x,i;
	int val[15];
	
	scanf("%d",&x);
	while(x--)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%d",&val[i]);
		}
		max = -10000000;
		fun(val,0,n,m,0,1);
		printf("%d\n",max);
	}
	return 0;
}

void fun(int *val,int index,int size,int m,int cnt,int res)
{
	if(m==cnt)
	{
		if(res > max)
		{
			max = res;
		}
		return ;
	}
	if(index>=size)
	{
		return ;
	}
	fun(val,index+1,size,m,cnt+1,res*val[index]);
	fun(val,index+1,size,m,cnt,res);
}

