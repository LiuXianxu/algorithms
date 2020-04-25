#include <iostream>
//#include <cstdio>
using namespace std;
#define MAX 400010
#define max(x,y) (((x)>(y))?(x):(y))
struct Node{
	int l,r;
	int sum,max;
}node[MAX];

void build(int n,int l,int r)
{
	node[n].l=l;
	node[n].r=r;
	node[n].max=0;
	node[n].sum=0;
	if(l==r)return;
	int middle = (l+r)/2;
	build(n*2,l,middle);
	build(n*2+1,middle+1,r);
}
void Insert(int n,int v,int val)
{
	node[n].sum+=val;
	node[n].max=max(node[n].max,val);
	if(node[n].l==node[n].r)return;
	int middle=(node[n].l+node[n].r)/2;
	if(v<=middle) Insert(n*2,v,val);
	else Insert(n*2+1,v,val);
}
void Modify(int n,int v,int val)
{
	
	if(node[n].l==node[n].r)
	{
		node[n].max=val;
		node[n].sum=val;
		return;
	}
	int middle = (node[n].l+node[n].r)/2;
	if(v<=middle)
	{
		Modify(2*n,v,val);
	}
	else
	{
		Modify(2*n+1,v,val);
	} 
	node[n].sum=node[n*2].sum+node[n*2+1].sum;
	node[n].max=max(node[n*2].max,node[n*2+1].max);	
	
}
int PartSum(int n,int x,int y)
{
	if(node[n].l==x&&node[n].r==y)
	{
		return node[n].sum;
	}
	int middle = (node[n].l+node[n].r)/2;
	if(y<=middle)
	{
		return PartSum(n*2,x,y);
	}
	else if (x>middle)
	{
		return PartSum(n*2+1,x,y);
	}
	else 
	{
		return PartSum(n*2,x,middle)+PartSum(n*2+1,middle+1,y);
	}
}
int PartMax(int n,int x,int y)
{
	if(node[n].l==x&&node[n].r==y)
	{
		return node[n].max;
	}
	int middle = (node[n].l+node[n].r)/2;
	if(y<=middle)
	{
		return PartMax(n*2,x,y);
	}
	else if(x>middle)
	{
		return PartMax(n*2+1,x,y);
	}
	else 
	{
		return max(PartMax(n*2,x,middle),PartMax(n*2+1,middle+1,y));
	}
}

int main()
{
	int i,n,m;
	int val;
	//freopen("C:\\Users\\ÎÒµÄµçÄÔ\\Downloads\\input1.txt","r",stdin);
	cin>>n;
	cin>>m;
	build(1,1,n);
	for(i=1;i<=n;i++)
	{
		cin>>val;
		Insert(1,i,val);
	}
	if(m<=0)return 0;
	while(m--)
	{
		int select,a,b;
		cin>>select>>a>>b;
		switch(select)
		{
			case 1:Modify(1,a,b);break;
			case 2:cout<<PartSum(1,a,b)<<endl;break;
			case 3:cout<<PartMax(1,a,b)<<endl;break;
		}
		
	}
	return 0;
}
 
