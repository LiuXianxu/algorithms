#include <iostream>  
#include <cmath> 
#include <cstdio> 
using namespace std;   
  
#define MAX_N 400010  
  
struct Node{  
    int l,r;   
    int sum,maxium;   
}node[MAX_N];  
  
void build(int n,int l,int r)  
{  
    node[n].l=l;   
    node[n].r=r;   
    node[n].maxium=0;   
    node[n].sum=0;   
  
    if (l==r) return;    
  
    int middle=(l+r)/2;   
    build(n*2,l,middle);   
    build(n*2+1,middle+1,r);   
}  
  
void Insert(int n,int v,int val)  
{  
    node[n].sum+=val;   
    node[n].maxium=max(node[n].maxium,val);   
  
    if (node[n].l==node[n].r) return;     
  
    int middle=(node[n].l+node[n].r)/2;   
    if (v<=middle) Insert(n*2,v,val);   
    else Insert(n*2+1,v,val);   
}  
  
void Modify(int n,int v,int val)  
{  
    if (node[n].l==node[n].r)  
    {  
        node[n].maxium=val;   
        node[n].sum=val;   
        return;   
    }  
  
    int middle=(node[n].l+node[n].r)/2;   
    if (v<=middle) Modify(n*2,v,val);   
    else Modify(n*2+1,v,val);   
  
    node[n].sum=node[n*2].sum+node[n*2+1].sum;   
    node[n].maxium=max(node[n*2].maxium,node[n*2+1].maxium);  
}  
  
int PartSum(int n,int x,int y)  
{  
    if (node[n].l==x&&node[n].r==y)  
    {  
        return node[n].sum;   
    }  
    int middle=(node[n].l+node[n].r)/2;   
    if (y<=middle)  
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
    if (node[n].l==x&&node[n].r==y)  
    {  
        return node[n].maxium;    
    }  
    int middle=(node[n].l+node[n].r)/2;   
    if (y<=middle)  
    {   
        return PartMax(n*2,x,y);   
    }
	else if (x>middle)  
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
    int n,m,val,p,x,y;   
    cin>>n>>m;    
    build(1,1,n);   
    for (int i=1;i<=n;i++)  
    {  
        cin>>val;   
        Insert(1,i,val);   
    }  
  
    while(m--){  
        cin>>p>>x>>y;   
        switch (p)  
        {   
        case 1:Modify(1,x,y); break;  
        case 2:cout<<PartSum(1,x,y)<<endl;break;   
        case 3:cout<<PartMax(1,x,y)<<endl;break;   
        }  
    }  
    cout<<endl;
  	/*   for (int i=1;i<=10;i++)  
    {  
    	printf("sum=%d,max=%d\n",node[i].sum,node[i].maxium);
    } 
	*/ 
    return 0;   
}  
