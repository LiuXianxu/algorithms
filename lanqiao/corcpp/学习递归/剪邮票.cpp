#include<iostream>
using namespace std;
int a[3][4];
int h=0;
int visited[3][4]={0};
void dfs(int x)
{
	if(x==5) 
	{
	/*	for(int i=0;i<3;i++)
	   	    for(int j=0;j<4;j++)
	    	    if(visited[i][j]==1) cout<<a[i][j];
	        		cout<<endl;
	*/	return;
	}
	for(int i=0;i<3;i++)
	        for(int j=0;j<4;j++)
	        {
	        	if(visited[i][j]==0) 
	        	{	
	        		visited[i][j]=1;
			     	h=a[i][j];
	       		    dfs(x+1);
	       		   	visited[i][j]=0;      		
				}
			}
}
int main()
{

	int s=0;
	for(int i=0;i<3;i++)
	for(int j=0;j<4;j++)
	a[i][j]=++s;
	dfs(0); 
	return 0;
}

