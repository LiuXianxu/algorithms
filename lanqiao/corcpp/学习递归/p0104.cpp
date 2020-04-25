#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	double a,b,c;
	cin>>a>>b>>c;
	if(b*b==4*a*c)
	{
		printf("x1 = %.6lf",-b/(2*a));
	}
	else if(b*b-4*a*c>0)
	{
		printf("x1 = %.6lf\n",(-b+sqrt(b*b-4*a*c))/(2*a));
		printf("x2 = %.6lf",(-b-sqrt(b*b-4*a*c))/(2*a));
	}
	else {
		cout<<"Error";
	}
	
	return 0;
}
 
