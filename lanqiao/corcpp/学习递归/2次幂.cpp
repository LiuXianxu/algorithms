#include<iostream>

using namespace std;

void pots(int n)
{
    int a[100];
    int num=0,c=0,m;
    
    //???????
    while(n)  
    {
        m=n%2;
        if(m!=0)
        {
            a[num++]=c;
        }
        c++;
        n/=2;
    }
    
    //??
    for(int i=num-1;i>=0;i--)
    {
        if(a[i]==0)
            cout<<"2(0)";
        else if(a[i]==1)
            cout<<"2";
        else if(a[i]==2)
            cout<<"2(2)";
        else if(a[i]>2)
        {
            cout<<"2(";
            pots(a[i]);
            cout<<")";
        }
        if(a[i]!=0)
            cout<<"+";
    }
}
int main()
{
    int n;
    cin>>n;
    pots(n);

    return 0;
}

