#include <iostream>
using namespace std;
int a[25];
int result[25];
int top=0;
int n,cnt=0;
long t;
void reverse(int a[],int n);
void dfs(int k,int sum);
int main()
{
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>t;
	reverse(a,n);
	dfs(0,0);
	cout<<cnt;
	return 0;
} 
void reverse(int a[],int n)
{
	int temp;
	for(int i=0;i<n/2;i++)
	{
		temp = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] =temp;
	}
}
void dfs(int k,int sum)
{
	if(k==n)
	{ 
		if(sum==t&&top!=0)
		{
			for(int i=top-1;i>=0;i--)
			{
				cout<<result[i]<<" ";
			}
			cnt++;
			cout<<endl;
		}
		return ;
	}
	dfs(k+1,sum);
	result[top++] = a[k];
	dfs(k+1,sum+a[k]);
	top--;
}
