#include<iostream>
#include<string.h>
#include<stdio.h>
#define N 100//用来控制它的最大行数
using namespace std;
char str[N][80];//用于存储文章
int l[N]={0};//用于记录每一行实际的字符个数
int n;//n用于记录实际的行数
char a[80];//要输入的目标字符串
void shuru()
{
	char ch,t;
	int i=0,j=0;
	n=1;
	ch='0';
	t='0';
	while(ch!='*')
	{
		for(i=0;i<n;i++)
		{
			for(j=0;;j++)
			{
				scanf("%c",&ch);
				if(ch=='*')
				{	
					t='*';
					break;
				}
				l[i]++;
				str[i][j]=ch;
			}
			if(ch=='\n')
			{
				n++;
			}	
		}
	}
	printf("输入完毕!");
}
void input()//这个函数用于输入要统计的字符串
{
	int k;
	char c;
	k=0;
	while(1)
	{
		scanf("%c",&c);
		if(c=='\n')
			break;
		a[k]=c;//保存输入的字符串
		k++;
	}
	a[k]='\0';//\0结尾
}
void print()//这个函数用户输入的各行字符
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<l[i];j++)
		printf("%c",str[i][j]);
	}
	printf("\n");
}
void tj()
{
	int i,j;
	int zm,kg,sz,bd,s;
	zm=kg=sz=bd=s=0;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<l[i];j++)
		{
			if(str[i][j]!='\n')
				s++;
			if((str[i][j]<='z'&&str[i][j]>='a')||(str[i][j]<='Z'&&str[i][j]>='A'))
				zm++;
			if(str[i][j]<='9'&&str[i][j]>='0')
				sz++;
			if(str[i][j]==' ')
				kg++;
		}
	}
printf("\n全部字母数为:%d\n",zm);
printf("\n全部数字为:%d\n",sz);
printf("\n全部空格数为:%d\n",kg);
printf("\n文章总字符数位:%d\n",s);

}
void look()//该函数用于统计某一字符串在文章中出现的次数
{
	int i,j,k,ml,y;//ml为目标字符串的长度
	int x=0;
	ml=0;
	ml=strlen(a);
	printf("--%d---\n",ml);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<l[i];j++)
		{
			y=0;
			if(j+1==l[i])break;//超过此行的最大长度
			for(k=0;k<ml;k++)
			{
				if(a[k]==str[i][j+k])
					y++;
				else break;
				
				if(y==ml)
					x++;
			}
			k=0;
	
	
		}
		for(i=0;i<ml;i++)
		printf("%c",a[i]);
	printf("在文中出现的次数为:%d\n",x);
	}
	
}
void dele()//该函数用于删除某一字符串并将删除后的字符串输出
{
	
	int i,j,k,ml,y;//ml为目标字符串的长度
	int x=0;n=0;
	ml=strlen(a);
	printf("--%d---\n",ml);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<l[i];j++)
		{
			y=0;
			if(j+1==l[i])break;//超过此行的最大长度
			for(k=0;k<ml;k++)
			{
				if(a[k]==str[i][j+k])
					y++;
				else break;
				
				if(y==ml)
				{
					n=j;
					for(;n+k+1<l[i];n++)
						str[i][n+k-ml+1]=str[i][n+k+1];
					l[i]=l[i]-ml;
				}
			}
			k=0;
		}
	}
	for(i=0;i<=n;i++)
		for(j=0;j<l[i];j++)
			printf("%c",str[i][j]);
	
}
void menu()
{
	int m;
	while(1)
	{
		printf("*********选择你需要的操作****************\n");
		//printf("*******:输入字符以*结束****************\n");
		printf("********1:输入原文**********************\n");
		printf("**2:统计文章中字母,数字,空格，文章总字数**\n");
		printf("***3:统计某一字符串出现的次数**********\n");
		printf("****4:删除某一字符串后并输出删除后的文章***\n");
		printf("******5:结束**************************\n");
		scanf("%d",&m);
		if(m==1)
			shuru();
		if(m==1)
			print();
		if(m==2)
			tj();
		if(m==3)
		{
			printf("请输入你要统计的字符串:\n");
			getchar();
			input();
			look();
		}
		if(m==4)
		{
			printf("请输入你要删除的字符串:\n");
			getchar();
			input();
			dele();
		}
		if(m==5)break;
	}
}
int main()
{
//	printf("请输入文章:\n");
//	shuru();
//	tj();
	//look();

	//shuru();
	/*FILE *fp=fopen("123.text","r"
		);为只读文件
	char ch;
	n=0;
	memset(l,0,sizeof(l));//初始化内存
	while(fscanf("%c",&ch)!=EOF)
	{
		str[n][l[n]]=ch;
		l[n]++;
		if(ch=='\n')
			n++;
		if(l[n]>80)
		{
			printf("输入错误!\n");
			break;
		}
	}*/
	menu();
	return 0;
}





