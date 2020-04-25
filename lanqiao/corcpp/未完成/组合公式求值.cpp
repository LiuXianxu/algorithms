#include <iostream>
#include <cmath>
using namespace std;
const int MOD = 987654321;
int C(int n,int m);
int main()
{
	int m,n,result=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		result += (C(n,m) * C(n,i)%MOD) * i*i*i % MOD;  
	}
	cout<<result;
	return 0;
} 
int C(int n,int m)
{
	int i,len=m;
	int x=n,y=m;
	for(i=1;i<len;i++)
	{
		n =x * (x-1) % MOD;
		x--;
	}
	for(i=1;i<len;i++)
	{
		m =y * (y-1) %MOD;
		y--;
	}
	return n/m;
}
 
