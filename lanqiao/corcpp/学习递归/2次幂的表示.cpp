#include<iostream> 
#include<stack>
using namespace std;
void f(int n); 
int main()
{
	int n;
	cin>>n;
	f(n);
	return 0;
} 
void f(int n)
{
	stack<int> stack;
	int m,i,c=0;
	while(n)
	{
		m=n%2;
		if(m)
		{
			stack.push(c);
		}
		c++;
		n/=2; 
	}
	for(i=stack.size()-1;i>=0;i--)
	{
		int t=stack.top();
		stack.pop();
		if(t==0)
		cout<<"2(0)";
		else if(t==1)
		cout<<"2";
		else if(t==2)
		cout<<"2(2)";
		else if(t>2)
		{
			cout<<"2(";
			f(t);
			cout<<")";
		}
		if(i!=0)
		cout<<"+";
	}
	
}
