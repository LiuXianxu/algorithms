#include <iostream>
using namespace std;
const int N = 10;
int main()
{
	int a[N];
	int i,j;
	for(i=0;i<N;i++)
	{
		cin>>a[i];
	}
	int temp;
	for(i=0;i<N-1;i++)
	{
		for(j=0;j<N-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	for(i=0;i<N;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
} 
