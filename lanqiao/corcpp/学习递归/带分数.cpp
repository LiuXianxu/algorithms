#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int num=1;
int sum=0;
int A=1,B=1,C=1;   //  num=a+b/c ,a,b,c����Ӧ�ĳ��� 
int abc[11];//����a,b,c��ֵ 
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
void f(int n)  //��c-b-a����λ��ȡֵ�ŵ�abc���鱣�棬�ж� 
{
  if(n>C+B)  //��֦ 
  {
  	 c=cal('C');
  	 b=cal('B');
  	if(b<c) return ; 
  }
  if(n==10)  //ȡֵ��� 
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
		  	abc[n]=i;//��λ����c��ֵ 
  	        f(n+1);
  	        abc[n]=0;
  			is[i]=0;
		} 		
	}	
}
int main()
{  
  cin>>num;
  for(C=1;C<=4;C++)  //��ĸ�������Ϊ4λ
  	for(B=C;B<=7,B+C<=8;B++)    //����λ�������ڸ�ĸλ����Ҫ��֤A�ĳ��� 
  	{
     	A=9-B-C;
	 	f(1);
 	} 
	cout<<sum<<endl;
	printf("Time used = %.2f",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}

