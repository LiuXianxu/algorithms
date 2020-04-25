#include <iostream>
using namespace std;
const int N = 1010;
int a[N];
int f(int n,int result);
int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<f(n,0);
	return 0;
} 
int f(int n,int result)
{
	//找到最小值 与 相邻较小的 相加
	//预计超时 
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<result<<endl;
	int i,j,k;
	if(n>1)
	{
		k=0;
		for(j=1;j<n;j++)
		{
			if(a[k]>a[j])
			{
				k=j;
			}			
		}
		if(k>0)
		{
		
			if(a[k-1]<=a[k+1])
			{
				result += a[k]+a[k-1];
				a[k-1] +=a[k];
				for(int i=k;i<n-1;i++)
				{
					a[i] = a[i+1];
				}
				f(n-1,result);
			}
			else
			{
				result += a[k]+a[k+1];
				a[k] += a[k+1];
				for(int i=k+1;i<n-1;i++)
				{
					a[i]=a[i+1];
				}
				f(n-1,result);
			}
		}
		else
		{
			result += a[0]+a[1];
			a[0] += a[1];
			for(int i=1;i<n-1;i++)
			{
				a[i]=a[i+1];
			}
			f(n-1,result);
		}
	}
	else if(n==1)
	{
	//	result += a[0]+a[1];
		return result;
	}
}
