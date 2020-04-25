#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int n,i; 
		cin>>n;
		for(i=2;i<=n;)
		{
			if(n%i==0&&i!=n)
			{
				cout<<i<<"*";
				n /= i;
			}
			else if(i==n)
			{
				cout<<i;
				i++;
			}
			else
			{
				i++;
			}
			
			
		}
	
	
	
	return 0;
} 
