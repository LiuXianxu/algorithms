#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
double map[50][100];

int main()
{
	int i,j;
	freopen("C:\\Users\\ÎÒµÄµçÄÔ\\Desktop\\in.txt","r",stdin);
	for(i=0;i<29;i++)
	{
		for(j=0;j<i+1;j++)
		{
			cin>>map[i][j];
		}
	}
	
	for(i=0;i<29;i++)
	{
		for(j=0;j<i+1;j++)
		{
			map[i+1][j] += map[i][j]/2;
			map[i+1][j+1] +=  map[i][j]/2;
			map[i][j]=0;
		} 
	} 
/*	for(i=0;i<31;i++)
	{
		for(j=0;j<i+1;j++)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
*/	
	set<double> s;
	for(j=0;j<30;j++)
	{
		s.insert(map[29][j]);
	}
	set<double>::iterator it;
	it=s.begin();
	double min= *it;
	cout<<*it<<endl;
	it=s.end();
	double max = *(--it);
	printf("%lf\n",2086458231/min*max);
	cout<<(*(--it) * (2086458231/min))<<endl;

	return 0;
}

