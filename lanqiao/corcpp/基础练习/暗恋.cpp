#include <iostream>
using namespace std;
int map[205][205];
int main()
{
	int r,c,i,j;
	cin>>r>>c;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>map[i][j];
		}
	}
	return 0;
} 
