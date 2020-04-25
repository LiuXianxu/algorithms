#include <iostream> 
using namespace std;
bool perfectNum(int n); 
int main()
{
	int n;
	cin>>n;
	if(perfectNum(n))
	cout<<"yes";
	else
	cout<<"no";
	return 0;
}
bool perfectNum(int n)
{
	int i;
	int s=n;
	for(i=1;i<n/2+1;i++)
	{
		if(n%i==0)
		{
			s-=i;
		}
	}
	if(s==0)return true;
	else return false;
}
