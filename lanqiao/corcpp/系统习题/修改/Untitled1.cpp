#include<iostream> 
#include<stdio.h>
#include<ctype.h>
using namespace std;
struct zi
{
	char data;
	zi *next;
};
void input(zi *l)
{
	cout<<"������һҳ����(������80���Ӵ�����#����!):"<<endl;
	while((l->data=getchar())!='#')
	{
		l->next=new zi;
		l=l->next;
	}
	l->next=NULL;
}
void look(zi *l)
{
	int n=0;
	char str[80],*q;
	zi *p;
	cout<<"������һ�ַ���:";
	cin>>str;
	while(l->next)
	{
		p=l;
		q=str;
		for(;*q!='\0'&&p->next;p=p->next,q++)
		{
			if(p->data!=*q)break;
			if(*q=='\0')
				n++;
		        l=l->next;
		}
		cout<<"�ַ���:"<<str<<"����"<<n<<"��\n";
	}
}
zi *dele(zi *l)
{
	zi *h=l;
	char str[80],*q;
	zi *p;
	cout<<"������Ӵ�:";
	cin>>str;
	if(h->data==*str)
	{
		for(p=h->next,q=str+1;*q!='\0'&&p->next;p=p->next,q++)
		if(p->data!=*q)break;
		if(q->next=='\0')l->next=p;
		else l=l->next;
	}
	return h;
}
void print1(zi *l)
{
	while(l->next)
	{
		cout<<l->data;
		l=l->next;

	}
	cout<<endl;
}
void print2(zi *l,int &p1,int &p2,int &p3,int &n)
{
	p1=p2=p3=n=0;
	for(;l->next;l=l->next,n++)
	{if(isalpha(l->data))p1++;
	  else if(isdigit(l->data))p2++;
	   else if(l->data==' ')p3++;// 
	   else if(l->data=='\n')n--;
	   cout<<"ȫ����ĸ��:"<<p1;
	   cout<<endl;
	   cout<<"ȫ������:"<<p2;
	   cout<<endl;
	   cout<<"ȫ���ո���:"<<p3;
	   cout<<endl;
	   cout<<"����������:"<<n<<endl;
	   }
}
int main()
{ 
 zi *l=new l;
 int p1,p2,p3,n,data;
 input(l);
 do
 {	cout<<"\n";
	cout<<"*****************************"<<endl;
	cout<<"1:ͳ����Ӣ����ĸ�ո����Լ���ƪ���µ�������\n"<<endl;
	cout<<"2:ͳ��ĳһ�ַ����������г��ֵĴ���:\n"<<endl;
	cout<<"3:ɾ��ĳһ�ַ�             \n"<<endl;
	cout<<"4:��������û�����ĸ����ַ�:\n"<<endl;
	cout<<"*****************************"<<endl;
	cin>>data;
	switch(data)
	{
	case 1:print2(l,p1,p2,p3,n);break;
	case 2:look(l);break;
	case 3:dele(l);
	case 4:print1(l);
	}
 }while(data);
 
 return 0;
}
