#include<iostream>
#include<string.h>
#include<stdio.h>
#define N 100//�������������������
using namespace std;
char str[N][80];//���ڴ洢����
int l[N]={0};//���ڼ�¼ÿһ��ʵ�ʵ��ַ�����
int n;//n���ڼ�¼ʵ�ʵ�����
char a[80];//Ҫ�����Ŀ���ַ���
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
	printf("�������!");
}
void input()//���������������Ҫͳ�Ƶ��ַ���
{
	int k;
	char c;
	k=0;
	while(1)
	{
		scanf("%c",&c);
		if(c=='\n')
			break;
		a[k]=c;//����������ַ���
		k++;
	}
	a[k]='\0';//\0��β
}
void print()//��������û�����ĸ����ַ�
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
printf("\nȫ����ĸ��Ϊ:%d\n",zm);
printf("\nȫ������Ϊ:%d\n",sz);
printf("\nȫ���ո���Ϊ:%d\n",kg);
printf("\n�������ַ���λ:%d\n",s);

}
void look()//�ú�������ͳ��ĳһ�ַ����������г��ֵĴ���
{
	int i,j,k,ml,y;//mlΪĿ���ַ����ĳ���
	int x=0;
	ml=0;
	ml=strlen(a);
	printf("--%d---\n",ml);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<l[i];j++)
		{
			y=0;
			if(j+1==l[i])break;//�������е���󳤶�
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
	printf("�����г��ֵĴ���Ϊ:%d\n",x);
	}
	
}
void dele()//�ú�������ɾ��ĳһ�ַ�������ɾ������ַ������
{
	
	int i,j,k,ml,y;//mlΪĿ���ַ����ĳ���
	int x=0;n=0;
	ml=strlen(a);
	printf("--%d---\n",ml);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<l[i];j++)
		{
			y=0;
			if(j+1==l[i])break;//�������е���󳤶�
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
		printf("*********ѡ������Ҫ�Ĳ���****************\n");
		//printf("*******:�����ַ���*����****************\n");
		printf("********1:����ԭ��**********************\n");
		printf("**2:ͳ����������ĸ,����,�ո�����������**\n");
		printf("***3:ͳ��ĳһ�ַ������ֵĴ���**********\n");
		printf("****4:ɾ��ĳһ�ַ��������ɾ���������***\n");
		printf("******5:����**************************\n");
		scanf("%d",&m);
		if(m==1)
			shuru();
		if(m==1)
			print();
		if(m==2)
			tj();
		if(m==3)
		{
			printf("��������Ҫͳ�Ƶ��ַ���:\n");
			getchar();
			input();
			look();
		}
		if(m==4)
		{
			printf("��������Ҫɾ�����ַ���:\n");
			getchar();
			input();
			dele();
		}
		if(m==5)break;
	}
}
int main()
{
//	printf("����������:\n");
//	shuru();
//	tj();
	//look();

	//shuru();
	/*FILE *fp=fopen("123.text","r"
		);Ϊֻ���ļ�
	char ch;
	n=0;
	memset(l,0,sizeof(l));//��ʼ���ڴ�
	while(fscanf("%c",&ch)!=EOF)
	{
		str[n][l[n]]=ch;
		l[n]++;
		if(ch=='\n')
			n++;
		if(l[n]>80)
		{
			printf("�������!\n");
			break;
		}
	}*/
	menu();
	return 0;
}





