#include<iostream>  
#include<stdio.h>  
#include<math.h>  
using namespace std;  
int main()  
{  
    int n,a[10001]={0},sum=0,k,i;  
    cin>>n;  
    k=n;  
    while(k!=1)  
    {  
        for(i=0;i<n;i++)  
        {     
            if(a[i]==0)  
            { sum++;  
                if(sum==3)  
                {    
                   a[i]=1;  
                   sum=0;  
                   k=k-1;  
                }  
            }  
        }  
    }  
    for(i=0;i<n;i++)  
    {  
        if(a[i]==0)  
        cout<<i+1<<endl;  
    }  
}  
