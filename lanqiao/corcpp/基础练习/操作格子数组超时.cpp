#include<stdio.h>  
int a[100010];  
void Fun1(int x,int y,int a[]){  
    a[x]=y;  
}  
int Fun2(int x,int y,int a[]){  
    int i,sum=0;  
    for(i=x;i<=y;i++)  
    sum+=a[i];  
    return sum;  
}  
int Fun3(int x,int y,int a[]){  
    int i,max=-999999;  
    for(i=x;i<=y;i++)  
    if(a[i]>max)  
    max=a[i];  
    return max;  
}  
int main()  
{  
    int i,n,m,p,x,y;  
    scanf("%d%d",&n,&m);  
    for(i=1;i<=n;i++)  
    scanf("%d",&a[i]);  
    while(m--)  
    {  
       scanf("%d%d%d",&p,&x,&y);  
       if(p==1){  
         Fun1(x,y,a);  
       }else if(p==2){  
         printf("%d\n",Fun2(x,y,a));     
       }else{  
         printf("%d\n",Fun3(x,y,a));    
       }  
    }  
    return 0;  
} 
