#include <iostream>
#include <cstdio>
using namespace std;
const int M=105,N=1005;
int matrix[M][N]={0};
int main()
{
	int i,j;
	int m,n;
	int v1,v2;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>v1>>v2;	
		matrix[v1][i]=1;
		matrix[v2][i]=-1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
/*
#include<iostream>  
#include<memory.h>
#include <cstdio>  
using namespace std;  
int main()  
{  
    int v,v1,v2,e,i,j;  
    int map[100][1000]={0};
	freopen("C:\\Users\\ÎÒµÄµçÄÔ\\Downloads\\input5.txt","r",stdin);  
    cin>>v>>e;  
    for(i=0; i<100; i++)  
       memset(map[i],0,sizeof(map[i]));  
    for(i=0; i<e; i++)  
    {  
        cin>>v1>>v2;  
        v1--;  
        v2--;  
        map[v1][i]=1;  
        map[v2][i]=-1;  
    }  
    for(i=0; i<v; i++)  
    {  
        for(j=0; j<e; j++)  
        {  
            cout<<map[i][j];  
            if(j<e-1)  
                cout<<' ';  
        }  
        cout<<endl;  
    }  
  
    return 0;  
}  */
