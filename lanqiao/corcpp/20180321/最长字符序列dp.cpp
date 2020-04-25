#include <iostream>
using namespace std;
int l[105][105];
void LCSLength(string x,string y);
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	LCSLength(s1,s2);
	int max=0;
	for(int i=0;i<=s1.length();i++)
	{
		for(int j=0;j<=s2.length();j++)
		{
			if(l[i][j]>max)
			{
				max =l[i][j];
			}
		}
	}
	cout<<max;
	return 0;
}
void LCSLength(string x,string y)
{
	int i,j;
	int m=x.length();
	int n=y.length();
	l[0][0]=0;
	for(i=1;i<=m;i++)
	{
		l[i][0]=0;
	}
	for(j=1;j<=n;j++)
	{
		l[0][j]=0;
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				l[i][j]=l[i-1][j-1]+1;
			}
			else if(l[i-1][j]>=l[i][j-1])
			{
				l[i][j]=l[i-1][j];
			}
			else
			{
				l[i][j]=l[i][j-1];
			}
		}
	}
} 
