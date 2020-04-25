#include<stdio.h>  
#define INF 0x3f3f3f3f  
int a[30];  
int main()  
{  
    int n,sum=0,maxx=0;  
    int ans=0;  
    scanf("%d",&n);  
    if(n<=0) return 0;//n<=0²»Êä³ö 
    a[0]=-INF;  
    int i;  
    for(i=1;i<=n;++i)  
    {  
        scanf("%d",a+i);  
        if(a[i]!=a[i-1])  
        {  
            if(sum>maxx)  
            {  
                maxx=sum;  
                ans=a[i-1];  
            }  
            sum=1;  
        }  
        else  
            ++sum;  
    }  
    if(sum>maxx)  
    {  
        maxx=sum;  
        ans=a[i-1];  
    }  
    printf("%d\n",ans);  
    return 0;  
}  
