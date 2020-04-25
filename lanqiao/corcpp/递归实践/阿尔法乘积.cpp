#include <iostream>
using namespace std;
int f(int x); 
int main()
{
	int n;
	cin>>n;
	cout<<f(n);
	return 0;
}
int f(int x)
{
	if(x<10)
	{
		return x;
	}
	else
	{
		int result=1;
		int temp;
		while(x)
		{
			temp=x%10;
			if(temp)
			{
				result *=temp;
			}
			x /= 10;
		}
		if(result>=10)
		{
			f(result);
		}
		else
		{
			return result;
		}
	}
}
