#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

typedef struct chuan
{
	char info;
	struct chuan *next;
}chuan;

chuan *head,*head1,*head2;//����һ��ȫ�ֱ���

void exit();//�˳�����
void print0();//��������û�����ĸ����ַ�
void print1();//���������ĸ�������������ո�����������������������
void print2();//�������ĳһ�ַ��������µĴ���
void shanchu();//�������ɾ���������
void shuru();//���������ַ�������
void menu();//����˵�
chuan *init();//��ʼ������

//����һ����ͷ��������������
chuan *init()
{
	chuan *head;
	head=(chuan *)malloc(sizeof(chuan));
	head->next=NULL;
	return head;
}
//����һ����ͷ�����Ӵ�������
chuan *init1()
{
	chuan *head1;
	head1=(chuan *)malloc(sizeof(chuan));
	head1->next=NULL;
	return head1;
}
//����һ����ͷ�����Ӵ�������
chuan *init2()
{
	chuan *head2;
	head2=(chuan *)malloc(sizeof(chuan));
	head2->next=NULL;
	return head2;
}
//���������ַ�������
void shuru()
{
	char ch;
	chuan *p,*r;//����һ��r��ָ�����һ���ַ�����Ӧ�Ľ��
	r=NULL;
	printf("������С�ڰ�ʮ���ַ�ÿ�У���'*'�������롣\n");
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
	printf("����ɹ���\n");

}

//��������û�����ĸ����ַ�
void print0()
{
	chuan *p;
	p=head->next;
	if(!p)	printf("�ձ����������ַ�����\n");
	else
	{
		printf("����Ϊ����:");
		while(p)	{	printf("%c",p->info);	p=p->next;	}
	}
	printf("\n");
}

//���������ĸ�������������ո�����������������������
void print1()
{
	int a,b,c,d,s;
	chuan *p;
	p=head->next;
	a=b=c=d=s=0;
	if(!p)	printf("�ձ����������ַ�����\n");
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
	printf("��ĸ��:%d,������:%d,�ո���:%d,��������:%d,��������:%d",a,b,c,d,s);
}

//�������ĳһ�ַ��������µĴ���
void print2()
{
	int i,j,time=0,prelength,qlength;
	chuan *pre,*q,*r,*p,*f;
	char ch;
	int count=0;
	pre=head->next;//������ַ����pre
	q=init1();
	prelength=qlength=0;

	printf("������һ���Ӵ�,��'*'������\n");
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

	while(pre)//����pre����
	{
		pre=pre->next;
		prelength++;
	}
	printf("pre���� %d\n",prelength);
	q=head1->next;
	while(q)//����q����
	{	
		qlength++;	
		q=q->next;
	}
	printf("q���� %d\n",qlength);

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
	
	printf("�Ӵ����ֵĴ��� %d\n",time);
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



//�������ɾ���������
void shanchu()
{
	int i,j,prelength=0,qlength=0;
	chuan *pre,*q,*p,*r,*f;
	char ch;
	int count=0,time=0;
	pre=head->next;//������ַ���¸���pre
	q=init2();

	printf("������һ��Ҫɾ�����Ӵ�,��'*'������\n");
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

	while(pre)//����pre����
	{
		pre=pre->next;
		prelength++;
	}
	printf("pre���� %d\n",prelength);
	q=head2->next;
	while(q)//����q����
	{	
		qlength++;	
		q=q->next;
	}
	printf("q���� %d\n",qlength);

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

//����˵�
void menu()
{
	int choose;
	printf("������������еĲ�����Ӧ�����֣�\n");
	printf("0--�˳�\n");
	printf("1--��������\n");
	printf("2--�����ĸ�������������ո�����������������������\n");
	printf("3--���ĳһ�ַ��������µĴ���\n");
	printf("4--���ɾ���������\n");
	printf("5--����û�����ĸ����ַ�\n");
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
	default: printf("��������ȷ�����֡�\n");
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
