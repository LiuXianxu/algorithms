#include <iostream>
using namespace std;
int n,cnt=0;
long t;
int flag=0;
long a[25],result[25];
void dfs(int x,long s,int k)
{
	if(s==t&&k>0&&flag)
	{
		cnt++;
		for(int i=k-1;i>=0;i--)
		{
			cout<<result[i];
			if(i!=0)
			cout<<" ";
		}
		cout<<endl;
		flag=0;
	}
	if(x==0)
		return ;
	dfs(x-1,s,k);
	flag=1;
	result[k]=a[x];
	dfs(x-1,s+a[x],k+1);
	
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>t;
	dfs(n,0,0);
	cout<<cnt;
	return 0;
} 
