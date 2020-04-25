#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int num=1;
int sum=0;
int A=1,B=1,C=1;   //  num=a+b/c ,a,b,c所对应的长度 
int abc[11];//储存a,b,c的值 
int is[10]={0}; 
int a=0,b=0,c=0;

int power(int x,int y)
{
	int pow =1;
	for(int i=0;i<y;i++)
		pow=pow*x;
	return pow;
}
int cal(char n)
{
	int sum=0;
	if(n=='C') 
		for(int i=1;i<=C;i++)
	 		sum+=abc[i]*power(10,C-i);

	if(n=='B')
		for(int i=C+1;i<=C+B;i++)
			sum+=abc[i]*power(10,C+B-i);
			
	if(n=='A')
		for(int i=C+B+1;i<=9;i++)
			sum+=abc[i]*power(10,9-i);
		
	
	return sum;
}
void f(int n)  //从c-b-a根据位数取值放到abc数组保存，判断 
{
  if(n>C+B)  //剪枝 
  {
  	 c=cal('C');
  	 b=cal('B');
  	if(b<c) return ; 
  }
  if(n==10)  //取值完毕 
  { 
  	a=cal('A');
  	if(a*c+b==num*c) 
	{ 
		printf("%d = ",num);
		for(int i=1;i<=A;i++)
			printf("%d",abc[B+C+i]);
		printf("+"); 
		for(int i=1;i<=B;i++)
			printf("%d",abc[C+i]);
		printf("/");
		for(int i=1;i<=C;i++)
			printf("%d",abc[i]);
		printf("\n");
	 sum++;
	}
  	return ;
  }
  	for(int i=1;i<=9;i++)
  	{
  		if(is[i]==0)
		{
		  	is[i]=1;
		  	abc[n]=i;//按位储存c的值 
  	        f(n+1);
  	        abc[n]=0;
  			is[i]=0;
		} 		
	}	
}
int main()
{  
  cin>>num;
  for(C=1;C<=4;C++)  //分母长度最多为4位
  	for(B=C;B<=7,B+C<=8;B++)    //分子位数不低于父母位数且要保证A的长度 
  	{
     	A=9-B-C;
	 	f(1);
 	} 
	cout<<sum<<endl;
	printf("Time used = %.2f",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

