#include <iostream>
using namespace std;
int main()
{
	int n;
	long a[30],T;
	int i,j=0,k,cnt=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>T;
	for(i=1;i<(1<<n);i++) 
	{
		long t=0;
		for(k=0;k<n;k++)
		{
			if(i&(1<<k)) 
			t+=a[k];
		}
		if(t==T)
		{
			for(k=0;k<n;k++)
			{
				if(i&(1<<k))
				cout<<a[k]<<" ";
			}
			cout<<endl;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
