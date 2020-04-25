#include <iostream>
using namespace std;
int avg(int n); 
int main()
{
	int n;
	cin>>n;
	cout<<avg(n);
	return 0;
}
int avg(int n)
{
	int i,sum=0;
	int *p= new int[n]();
	for(i=0;i<n;i++)
	{
		cin>>*(p+i);
		sum+=*(p+i);
	}
	return sum/n;
}
