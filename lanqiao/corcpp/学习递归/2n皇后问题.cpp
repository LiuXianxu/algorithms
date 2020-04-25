#include <iostream>
#include <cstdio>
using namespace std;
int chessb[9][9]; //�������̳�ʼ״̬ 
int b[9]; //�׻ʺ�ķ���λ�ã�i���ǵ�x�У�b��i��=x�� 
int h[9];
int cnt=0; //���㷽���� 
int check(int queue[],int n) // �ж�ͬһ�л������Խ����Ƿ��Ѿ������� 
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
void bai(int line,int n) // �Ű��� 
{
	int i;
	if(line==n+1)     //�ѷź� 
	{
		cnt++;
	}
	else 
	{
		for(i=1;i<=n;i++)
		{
			if(chessb[line][i]==1&&i!=h[line])  //���Է��� 
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

void hei(int line,int n) //�ڻʺ������ 
{
	int i;
	if(line==n+1) //�ڻʺ��ѷź� 
	{
		bai(1,n); //��ʼ�����׻ʺ� 
	}
	else 
	{
		for(i=1;i<=n;i++)
		{
			if(chessb[line][i]==1) // ���Է��� 
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
