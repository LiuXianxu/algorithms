#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

typedef struct chuan
{
	char info;
	struct chuan *next;
}chuan;

chuan *head,*head1,*head2;//定义一个全局变量

void exit();//退出函数
void print0();//定义输出用户输入的各行字符
void print1();//定义输出字母数、数字数、空格数、标点符号数和文章总数
void print2();//定义输出某一字符串在文章的次数
void shanchu();//定义输出删除后的文章
void shuru();//定义输入字符串函数
void menu();//定义菜单
chuan *init();//初始化链表

//建立一个带头结点的主串单链表
chuan *init()
{
	chuan *head;
	head=(chuan *)malloc(sizeof(chuan));
	head->next=NULL;
	return head;
}
//建立一个带头结点的子串单链表
chuan *init1()
{
	chuan *head1;
	head1=(chuan *)malloc(sizeof(chuan));
	head1->next=NULL;
	return head1;
}
//建立一个带头结点的子串单链表
chuan *init2()
{
	chuan *head2;
	head2=(chuan *)malloc(sizeof(chuan));
	head2->next=NULL;
	return head2;
}
//定义输入字符串函数
void shuru()
{
	char ch;
	chuan *p,*r;//定义一个r来指向最后一个字符所对应的结点
	r=NULL;
	printf("请输入小于八十个字符每行，用'*'结束输入。\n");
	while((ch=getchar())!='*')
	{
		p=(chuan *)malloc(sizeof(chuan));
		p->info=ch;
		if(head->next==NULL)
			head->next=p;
		else	r->next=p;
		r=p;
	}
	if(r!=NULL)	r->next=NULL;
	printf("输入成功！\n");

}

//定义输出用户输入的各行字符
void print0()
{
	chuan *p;
	p=head->next;
	if(!p)	printf("空表，请先输入字符串。\n");
	else
	{
		printf("内容为如下:");
		while(p)	{	printf("%c",p->info);	p=p->next;	}
	}
	printf("\n");
}

//定义输出字母数、数字数、空格数、标点符号数和文章总数
void print1()
{
	int a,b,c,d,s;
	chuan *p;
	p=head->next;
	a=b=c=d=s=0;
	if(!p)	printf("空表，请先输入字符串。\n");
	else
	{
		while(p)	
		{
			if('a'<=p->info&&p->info<='z'||'A'<=p->info&&p->info<='Z')	{a++;s++;}
			if('0'<=p->info&&p->info<='9') 	{b++;s++;}
			if(p->info==' ')	{c++;s++;}
			if(p->info==','||p->info=='.'||p->info=='!') 	{d++;s++;}
			p=p->next;
		}
	}
	printf("字母数:%d,数字数:%d,空格数:%d,标点符号数:%d,文章总数:%d",a,b,c,d,s);
}

//定义输出某一字符串在文章的次数
void print2()
{
	int i,j,time=0,prelength,qlength;
	chuan *pre,*q,*r,*p,*f;
	char ch;
	int count=0;
	pre=head->next;//主串地址赋给pre
	q=init1();
	prelength=qlength=0;

	printf("请输入一个子串,用'*'结束。\n");
	while((ch=getchar())!='*')
	{
		p=(chuan *)malloc(sizeof(chuan));
		p->info=ch;
		if(head1->next==NULL)
			head1->next=p;
		else	r->next=p;
		r=p;
	}
	if(r!=NULL)	r->next=NULL;

	while(pre)//计算pre长度
	{
		pre=pre->next;
		prelength++;
	}
	printf("pre长度 %d\n",prelength);
	q=head1->next;
	while(q)//计算q长度
	{	
		qlength++;	
		q=q->next;
	}
	printf("q长度 %d\n",qlength);

	i=prelength;j=qlength;//succ=0;
	
	pre=head->next;q=head1->next;
	while(pre)
	{
	//	printf("pre->info=%c;q->info=%c\n",pre->info,q->info);
		if(q&&count<j&&pre->info==q->info)
		{
			f=pre;
			pre=pre->next;
			q=q->next;
			count++;
		}
		else if(count!=0&&count<j)
		{
			q=head1->next;
			count=0;
		}
		else if(count==j)
		{
			time++;
			count=0;
			q=head1->next;	
		}
		else if(count==0)
		{
			pre=pre->next;
			q=head1->next;
		}
		else if(!q)
		{
			q=head1->next;
		}
	}
	if(count==j)time++;
	
	printf("子串出现的次数 %d\n",time);
}
/*	while(pre&&p&&prelength-plength>=i)
	{
		if(p->info==pre->info)
		{p=p->next;succ=1;}
		pre=pre->next;
		i++;
	}*/
/*	i=time=succ=0;
	while((i<=prelength-qlength)&&(!succ))
	{
		j=0;succ=1;
		while((j<=qlength)&& succ)
		{
			if((pre+j)->info==(q+i+j)->info) j++;
			else succ=0;
			++i;
		}
		if(succ)	time++;
		
	}
*/
	/*f=pre;
	i=prelength;j=qlength;succ=0;
	while(i>=0 &&j>=0)
	{
		if ((pre->info==q->info)&&(!succ))
		{
			f=pre;
			pre=pre->next;
			q=q->next;
			i--;
		}
		else
		{
			if(succ==0)
			{
				pre=f;
				q=head1->next;
				succ=1;
			}
			else
			{
				pre=pre->next;
				q=head1->next;
			}
		}
		if(q->next==NULL)
		{
			q=head1->next;
			time++;
		}
	}
//	printf("%d,%d",i,j);
	printf("%d\n",time);
	*/



//定义输出删除后的文章
void shanchu()
{
	int i,j,prelength=0,qlength=0;
	chuan *pre,*q,*p,*r,*f;
	char ch;
	int count=0,time=0;
	pre=head->next;//主串地址重新赋给pre
	q=init2();

	printf("请输入一个要删除的子串,用'*'结束。\n");
	while((ch=getchar())!='*')
	{
		p=(chuan *)malloc(sizeof(chuan));
		p->info=ch;
		if(head2->next==NULL)
			head2->next=p;
		else	r->next=p;
		r=p;
	}
	if(r!=NULL)	r->next=NULL;

	while(pre)//计算pre长度
	{
		pre=pre->next;
		prelength++;
	}
	printf("pre长度 %d\n",prelength);
	q=head2->next;
	while(q)//计算q长度
	{	
		qlength++;	
		q=q->next;
	}
	printf("q长度 %d\n",qlength);

	i=prelength;j=qlength;
	
	pre=head->next;
	q=head2->next;
//	f=head->next;
	if(j>i) printf("error!\n");
	chuan *temp1,*temp2;
	//temp1=head;
	int flag=0;
	
	while(pre){
		f=head;		
		while(q){
			if(q&&pre&&pre->info!=q->info)
				flag=1;
		if(pre->next)	pre=pre->next;
			q=q->next;
		}
		if(flag)	pre=f->next;
		else{
			f->next=pre->next;
		}
		q=head2->next;
	}
	
	
	
	
	/*while(pre)
	{
		if(q&&pre->info!=q->info)
		{
			f=pre;
			pre=pre->next;
			q=head2->next;
		}
		if(q&&pre->info==q->info)
		{
			pre=pre->next;
			q=q->next;
		}
		if(q==NULL)
		{
			f->next=pre->next;
			break;
		}
	}
	while(pre)
	{
		printf("%s",pre->info);
	}*/
}

/*	while(pre)
	{
		if(q&&count<j&&pre->info==q->info)
		{
			f=pre;
			pre=pre->next;
			q=q->next;
			count++;
		}
		else if(count!=0&&count<j)
		{
			q=head2->next;
			count=0;
		}
		else if(count==j)
		{
			count=0;
			q=head2->next;	
		}
		else if(count==0)
		{
			pre=pre->next;
			q=head2->next;
		}
		else if(!q)
		{
			q=head2->next;
		}
	}
	
}*/

//定义菜单
void menu()
{
	int choose;
	printf("请输入你想进行的操作对应的数字：\n");
	printf("0--退出\n");
	printf("1--输入文字\n");
	printf("2--输出字母数、数字数、空格数、标点符号数和文章总数\n");
	printf("3--输出某一字符串在文章的次数\n");
	printf("4--输出删除后的文章\n");
	printf("5--输出用户输入的各行字符\n");
	scanf("%d",&choose);
	setbuf(stdin,NULL);
	switch(choose)
	{
	case 0: exit(0);break;
	case 1: shuru();break;
	case 2: print1();break;
	case 3: print2();break;
	case 4: shanchu();break;
	case 5:	print0();break;
	default: printf("请输入正确的数字。\n");
	}
	menu();
}

int main()
{
	head=init();
	head1=init();
	head2=init(); 
	menu();
	return 0;
}
