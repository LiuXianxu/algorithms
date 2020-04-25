#include <iostream>
using namespace std;
int main()
{
	int a,b,n,sum;
	cin>>n;
	a=1;
	b=a+1;
	sum=0;
	while(b!=a+1||sum<n)
	{
		if(sum<n)
		{
			b++;
		}
		else
		{
			a++;
			b=a+1;
		}
		sum=(a+b)*(b-a+1)/2;
		if(sum==n)
		{
			cout<<a<<" "<<b<<endl;
		}
	}
	return 0;
} 
