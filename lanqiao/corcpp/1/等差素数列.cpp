#include <iostream>
using namespace std;
bool prime(long long n)
{
	if(n<=1||n>2&&n%2==0)
	{
		return false;
	}
	for(int i=3;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n,d;
	for(d=2;d<=1000;d++)
	{
		for(n=1;n<=1000;n++)
		{
			if(prime(n)
			&&prime(n+d)
			&&prime(n+2*d)
			&&prime(n+3*d)
			&&prime(n+4*d)
			&&prime(n+5*d)
			&&prime(n+6*d)
			&&prime(n+7*d)
			&&prime(n+8*d)
			&&prime(n+9*d)
			)
			{
				cout<<d;
				break;
			}
		}
	}
	
	return 0;
}
