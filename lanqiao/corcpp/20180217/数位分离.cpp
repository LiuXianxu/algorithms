#include <iostream>
#include <stack>
using namespace std;
int main()
{
	int n;
	stack<int> s;
	cin>>n; 
	do
	{
		s.push(n%10);
		n/=10;
	}while(n>0);
	while(s.empty()==false)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}
