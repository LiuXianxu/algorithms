#include <iostream>
using namespace std;
int DivisorSum(int n);
int main()
{
	int n1,n2;
	cin>>n1>>n2;
	if(n1==DivisorSum(n2)&&n2==DivisorSum(n1))
	{
		cout<<"yes";
	}
	else
	{
		cout<<"no";
	}
	
	return 0;
}
int DivisorSum(int n)
{
	int sum=1;
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
		{
			sum=sum+i;
		}
	}
	return sum;
}
