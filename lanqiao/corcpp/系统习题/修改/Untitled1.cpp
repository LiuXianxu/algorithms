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
	cout<<"请输入一页文字(不超过80个子串，以#结束!):"<<endl;
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
	cout<<"请输入一字符串:";
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
		cout<<"字符串:"<<str<<"出现"<<n<<"次\n";
	}
}
zi *dele(zi *l)
{
	zi *h=l;
	char str[80],*q;
	zi *p;
	cout<<"输入该子串:";
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
	   cout<<"全部字母数:"<<p1;
	   cout<<endl;
	   cout<<"全部数字:"<<p2;
	   cout<<endl;
	   cout<<"全部空格数:"<<p3;
	   cout<<endl;
	   cout<<"文章总字数:"<<n<<endl;
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
	cout<<"1:统计中英文字母空格数以及整篇文章的总字数\n"<<endl;
	cout<<"2:统计某一字符串在文章中出现的次数:\n"<<endl;
	cout<<"3:删除某一字符             \n"<<endl;
	cout<<"4:分行输出用户输入的各行字符:\n"<<endl;
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
