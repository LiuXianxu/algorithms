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
int a[3][4]={0};//����ȡ���ļ����� 
int visited[13]={0};//����dfs��ȡ����5�����ֲ�ͬ����Ʊ 
int mark[3][4]={0};//����bfs�ж���������Ʊ�Ƿ񱻳�ȡ�� 
int x[4]={-1,0,1,0},y[4]={0,1,0,-1};  //������·������4��forѭ�������������� 
int bfs_mark[3][4]={0};
int h[5]={0};//��¼ȡ����5����Ʊ 
int xx,yy;//��¼��һ����Ʊ��λ�ã�������ջ 
int bfs();//ǰ������ 
void dfs(int x)//����ѡȡ5���������ִӴ�С 
{
	if(x==5) //����5��ʱ 
	{ 
       	  Point p1; p1.x=xx; p1.y=yy; //��֤ÿ��ȡ��5����Ʊ����ʼ��һ����������ж�;
	            que.push(p1);
		int  is_connect=bfs();//�ж�5���Ƿ�����
		if(is_connect) 
		 sum++;
		return;
	}
	else	
	for(int i=0;i<3;i++)       //���������Ŀ����������Ҽ�¼ 
			for(int j=0;j<4;j++)
		  if(visited[a[i][j]]==0) //����ȡ 
		  {
		  	if(x==0)   //��¼��Ʊ�Ŀ��� 
		  	{
		  	   xx=i;yy=j;h[0]=a[i][j];	
			}
			if(a[i][j]>h[x-1]) //��֤ȡ������Ʊ��ֵ���� 
			{
			h[x]=a[i][j];
			visited[a[i][j]]=1;
		  	mark[i][j]=1; //(i,j)����Ʊ����5��֮�� 
		  	dfs(x+1);//��һ���������б����ʱ�򣬺��п���Ϊ�߼�˼�������dfs(x++)���ֵ����˱��� 
		  	visited[a[i][j]]=0;
		  	mark[i][j]=0; 
		  	 h[x]=0;
			}
		  	    	
		 }
}
int bfs()//����ѡ������Ʊ���ж��Ƿ�����
{	 
	 int i,count=0,a,b;  	          
	while(!que.empty()) 
	{
		Point p1=que.front(); //ÿ���ж϶��Զ��е�ͷ��������С����Ʊ5���ĵ�һ��������bfs �൱��dfs����㣬dfs(0) 
		int xx=p1.x;
		int yy=p1.y; 
		que.pop(); 		
		count++;
		bfs_mark[xx][yy]=1;//�Ѿ�bfs�� ʹ���ѱ���¼count�����ݲ����ٴ�bfs����ֹ������� 
		for(i=0;i<4;i++) //��dfs��forѭ������,���forѭ����bfs�ĺ��ģ�Ҳ���ǵ�����ĳ����ʱ���������ֵ���� 
		{                    
			a=p1.x+x[i];
			b=p1.y+y[i];
			if(a>=0&&a<3&&b>=0&&b<4&&mark[a][b]==1&&bfs_mark[a][b]==0)
			{
				Point p2;
				p2.x=a;
				p2.y=b;
				bfs_mark[a][b]=1;//���۽��ӻ��ǳ��ӣ�ֻҪ���������ʹ����Ѿ�bfs�ˣ������ٴ� 
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
	dfs(0);//����һ�� 
	cout<<sum;
	return 0;
}

