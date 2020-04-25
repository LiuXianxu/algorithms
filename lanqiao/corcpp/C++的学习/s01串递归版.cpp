#include <iostream>
using namespace std;
string s01(int n); 
int main()
{
	int n;
	cin>>n;
	cout<<s01(n);
	return 0;
} 
string s01(int n)
{
	if(n==0)
	return "0";
	else if(n==1)
	return "1";
	else return s01(n-2)+s01(n-1);
}
