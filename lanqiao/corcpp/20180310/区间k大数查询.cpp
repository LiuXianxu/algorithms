#include <iostream>
#include <algorithm>
using namespace std;
int a[1005];
int thek(int l,int r,int k);
int main()
{
	int i,n,m,l,r,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	if(m<0)return 0;
	while(m)
	{
		cin>>l>>r>>k;
		cout<<thek(l,r,k)<<endl;
		m--;
	}
	return 0;
}
int thek(int l,int r,int k)
{
	int *temp=NULL;
	temp = new int[r-l+1]();
	int j=0;
	for(int i=l;i<=r;i++)
	{
		*(temp+j)=a[i];
		j++;
	} 
	sort(temp,temp+j,greater<int>());
	a[0]= *(temp+k-1);
	delete []temp;
	return a[0];
}
