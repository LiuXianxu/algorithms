#include<iostream>
using namespace std;
int GetNum(int x);
int GetA(int x,int y);
int main()
{
		int n;
		int i,x,y,j;
//		cout<<"范围：-2147483647~2147483647\n输入阿拉伯数字：";
	    cin>>n;
//	    cout<<"转换为中文数字：";
		y=0;
		if(n!=0)
		{
//		if(n<0){cout<<"负";n*=-1;}
		x=n/100000000;
		if(GetA(x,0)){cout<<"yi ";y=1;}
		x=n%100000000/10000;
		if(GetA(x,y)){cout<<"wan ";y=1;}
		else y=0;
		x=n%10000;
		GetA(x,y);
	    }
	    else
	    cout<<"ling";
		cout<<"\n";
	    
	return 0;
}
int GetNum(int x)
{
	switch(x)
	{
	case 1:cout<<"yi ";break;
	case 2:cout<<"er "; break;
	case 3:cout<<"san "; break;
	case 4:cout<<"si "; break;
	case 5:cout<<"wu "; break;
	case 6:cout<<"liu "; break;
	case 7:cout<<"qi "; break;
	case 8:cout<<"ba "; break;
	case 9:cout<<"jiu "; break;
    }
	if(x==0) return 0;
	return 1;
}
int GetA(int x,int y)
{
	int a,t=0;
	a=x/1000;
	if(x<1000&&y==1&&x>0)cout<<"ling "; 
	if(a!=0)
	{
		GetNum(a);
		cout<<"qian "; 
		t=1;
	}
	a=x%1000/100;
	if(a!=0)
	{
		GetNum(a);
		cout<<"bai ";
		t=2;
	}
	a=x%100/10;
	if(a!=0)
	{
		if(t==1)cout<<"ling ";
		GetNum(a);
		cout<<"shi ";
		t=3;
	}
	a=x%10;
	if(a!=0)
	{
		if(t==1||t==2)cout<<"ling ";
		GetNum(a);
	}
	if(x!=0)return 1;
	return 0;
}
