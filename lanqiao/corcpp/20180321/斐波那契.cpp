#include<iostream>
using namespace std;
int f[100000];
int main()
{
	int n,m,p;
	int result=0;
	f[0]=0;
	f[1]=1;
	f[2]=1;
	cin>>n>>m>>p;
	for(int i=3;i<=n+2||i<=m;i++)
	{
		if(i>m) 
		{
			f[i]=(f[i-1]+f[i-2])%f[m];
		}
		else
		{
			f[i]=f[i-1]+f[i-2];
		}
		
	}
	result += (f[n+2]-1)%f[m]%p;
	cout<<result;
	return 0;
} 
