#include <iostream>
#include <cstdio>
using namespace std;
int chessb[9][9]; //保存棋盘初始状态 
int b[9]; //白皇后的放置位置，i行是第x列：b【i】=x； 
int h[9];
int cnt=0; //计算方案数 
int check(int queue[],int n) // 判断同一列或者两对角线是否已经放置了 
{
	int i;
	for(i=1;i<n;i++)
	{
		int judge = queue[i] - queue[n];
		if(judge==0||judge==i-n||judge==n-i)
		{
			return 0;
		}
	}	
	return 1;
}
void bai(int line,int n) // 放白棋 
{
	int i;
	if(line==n+1)     //已放好 
	{
		cnt++;
	}
	else 
	{
		for(i=1;i<=n;i++)
		{
			if(chessb[line][i]==1&&i!=h[line])  //可以放置 
			{
				b[line]=i;
				if(check(b,line))
				{
					bai(line+1,n);
				}
			}
		}
	}
	
}

void hei(int line,int n) //黑皇后的搜索 
{
	int i;
	if(line==n+1) //黑皇后已放好 
	{
		bai(1,n); //开始搜索白皇后 
	}
	else 
	{
		for(i=1;i<=n;i++)
		{
			if(chessb[line][i]==1) // 可以放置 
			{
				h[line]=i;
				if(check(h,line))
				{
					hei(line+1,n);
				}
			}
		}
	}
}

int main()
{
	int n,i,j;
//	freopen("d:\\input.txt","r",stdin); 
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&chessb[i][j]);
		}
	}
	hei(1,n);
	cout<<cnt;
	return 0;
} 
