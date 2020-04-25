#include <stdio.h>
int x=0,cnt=0,n=0;
int a=0,b=0,c=0;
void Swap(int *a,int *b)
{
	int temp =*a;
	*a=*b;
	*b=temp;
}
int getNum(int list[],int f,int r)
{
	int num=0;
	int i;
	for(i=f;i<=r;i++)
	{
		num=num*10+list[i]; 
	}
	return num;
} 
void dfs(int list[],int k,int m)
{
	int i;
	if(k==m-1)
	{
		for(i=0;i<=x;i++)
		{		
			int blast=0;
			int j;
			a=getNum(list,0,i);
			blast=((n-a)*list[8])%10;
			for(j=i+1;j<8;j++)
			{
				if(list[j]==blast)
				{
					b=getNum(list,i+1,j);
					c=getNum(list,j+1,8);
					if(b%c==0&&a+b/c==n)
					{
						cnt++;
					}
					break;
				}
				
			}	
		}
	} 
	else 
	{
		for(i=k;i<m;i++)
		{
			if(i!=k)
				Swap(&list[k],&list[i]);
			dfs(list,k+1,m);	
			if(i!=k)
				Swap(&list[k],&list[i]);
		}
	}
	
	
}
int main(){
	int list[]={1,2,3,4,5,6,7,8,9};
	int t=0;
	scanf("%d",&n);
	t=n;
	while(t)
	{
		++x;
		t/=10;
	}
	dfs(list,0,9);
	printf("%d",cnt);
	return 0;
}
