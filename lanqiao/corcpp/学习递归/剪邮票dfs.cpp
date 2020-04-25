#include<iostream>
#include<queue>
using namespace std;
struct Point
{
  int x;
  int y;	
};
queue<Point>que;
int sum=0;
int a[3][4]={0};//代表取了哪几个数 
int visited[13]={0};//用于dfs抽取任意5张数字不同的邮票 
int mark[3][4]={0};//用于bfs判断相连的邮票是否被抽取到 
int x[4]={-1,0,1,0},y[4]={0,1,0,-1};  //坐标套路，用于4次for循坏进行上下左右 
int bfs_mark[3][4]={0};
int h[5]={0};//记录取出的5个邮票 
int xx,yy;//记录第一个邮票的位置，方便入栈 
int bfs();//前置声明 
void dfs(int x)//任意选取5个，且数字从大到小 
{
	if(x==5) //剪完5个时 
	{ 
       	  Point p1; p1.x=xx; p1.y=yy; //保证每次取出5张邮票都能始第一个进行入队判断;
	            que.push(p1);
		int  is_connect=bfs();//判断5个是否相连
		if(is_connect) 
		 sum++;
		return;
	}
	else	
	for(int i=0;i<3;i++)       //有坐标的题目最好用坐标且记录 
			for(int j=0;j<4;j++)
		  if(visited[a[i][j]]==0) //可以取 
		  {
		  	if(x==0)   //记录邮票的开端 
		  	{
		  	   xx=i;yy=j;h[0]=a[i][j];	
			}
			if(a[i][j]>h[x-1]) //保证取出的邮票数值递增 
			{
			h[x]=a[i][j];
			visited[a[i][j]]=1;
		  	mark[i][j]=1; //(i,j)处邮票已在5张之中 
		  	dfs(x+1);//当一个程序运行报错的时候，很有可能为逻辑思想错误，如dfs(x++)，又调用了本身 
		  	visited[a[i][j]]=0;
		  	mark[i][j]=0; 
		  	 h[x]=0;
			}
		  	    	
		 }
}
int bfs()//操作选出的邮票，判断是否相连
{	 
	 int i,count=0,a,b;  	          
	while(!que.empty()) 
	{
		Point p1=que.front(); //每次判断都以队列的头（数字最小的邮票5个的第一个）进行bfs 相当于dfs的起点，dfs(0) 
		int xx=p1.x;
		int yy=p1.y; 
		que.pop(); 		
		count++;
		bfs_mark[xx][yy]=1;//已经bfs了 使得已被记录count的数据不被再次bfs，防止二次入队 
		for(i=0;i<4;i++) //与dfs的for循环类似,这个for循环是bfs的核心，也就是当处于某个点时，它所出现的情况 
		{                    
			a=p1.x+x[i];
			b=p1.y+y[i];
			if(a>=0&&a<3&&b>=0&&b<4&&mark[a][b]==1&&bfs_mark[a][b]==0)
			{
				Point p2;
				p2.x=a;
				p2.y=b;
				bfs_mark[a][b]=1;//无论进队还是出队，只要遍历过，就代表已经bfs了，不能再次 
				que.push(p2);	
			}
		}
	} 
      for(int i=0;i<3;i++)
	  for(int j=0;j<4;j++)
	  bfs_mark[i][j]=0;//reset 
	if(count==5)
	{
		for(int i=0;i<5;i++)
		{	
			cout<<h[i];
			if(i==4) cout<<endl;
		}
		return 1; 
	}        	
	else 
		 return 0;			
}
int main()
{  int s=0; 
	for(int i=0;i<3;i++)
	for(int j=0;j<4;j++)
	a[i][j]=++s;
	dfs(0);//剪第一张 
	cout<<sum;
	return 0;
}

