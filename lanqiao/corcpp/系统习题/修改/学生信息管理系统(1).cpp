/*����:����һ��ѧ������student(ѧ��,����,���ſγ̳ɼ�),ѧ��˳���studsqlist,����ѧ�������ѧ������
  ͨ����ϵͳ����ʵ�����¹���:
  ¼��:����ÿλѧ������Ϣ;
  ���:���ÿλѧ������Ϣ;
  ��ѯ:���԰�ѧ�Ż�������ѯĳ��ѧ������Ϣ;
  �޸�:�����޸�ѧ������Ϣ;
  ����:���Բ���һ��ѧ������Ϣ;
  ɾ��:����ɾ������������ѧ����Ϣ;
  ����:���԰�ѧ�����ܳɼ�����
*/      
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000
typedef struct
{
	char no[11];//ѧ��
	char name[15];//����
	int score[4];//���Ʒ���
}student;
typedef struct
{
	student s[MAXSIZE];//ѧ������
	int sum_score[MAXSIZE];//�ܷ�����
	int s_num;//������
}studsqlist;
int i;

//�˵�ѡ����
int menu_select()
{
	int choice;
	printf("**********************ѧ����Ϣ����ϵͳ********************\n");
	printf("                         1  ¼��                          \n");
	printf("                         2  ���                          \n");
	printf("                         3  ��ѯ                          \n");
	printf("                         4  �޸�                          \n");
	printf("                         5  ����                          \n");
	printf("                         6  ɾ��                          \n");
	printf("                         7  ����                          \n");
	printf("                         8  �˳�                          \n");
	printf("����������ѡ��(1-8)");
	scanf("%d",&choice);
	return choice;
}

//¼��:����ÿλѧ������Ϣ
void create(studsqlist *p)
{
	p->s_num=0;
	printf("�Ƿ�ʼ¼��ѧ����Ϣ?������һ���ַ�:(Y��ʾyes,N��ʾno)\n");
	char ch;
	i=0;
	scanf("%c",&ch);
	while(ch=='Y')
	{
		printf("������ѧ������Ϣ:\n");
		printf("ѧ��:");
		scanf("%s",&p->s[i].no);
		printf("����:");
		scanf("%s",&p->s[i].name);
		printf("��ѧ�ɼ�:");
		scanf("%d",&p->s[i].score[0]);
		printf("Ӣ��ɼ�:");
		scanf("%d",&p->s[i].score[1]);
		printf("���ĳɼ�:");
		scanf("%d",&p->s[i].score[2]);
		printf("��ʷ�ɼ�:");
		scanf("%d",&p->s[i].score[3]);
		p->s_num++;
		i++;
		ch=NULL;
		getchar();
		printf("�Ƿ�ʼ¼��ѧ����Ϣ?������һ���ַ�:(Y��ʾyes,N��ʾno)\n");
		scanf("%c",&ch);
	}
	if(ch!='Y')
	{
		printf("�����˳�¼����Ϣ����!\n");
	}
}

//���:���ÿλѧ������Ϣ
void print(studsqlist p)
{
	for(i=0;i<p.s_num;i++)
	{
		printf("ѧ��:%s\n",p.s[i].no);
		printf("����:%s\n",p.s[i].name);
		printf("��ѧ�ɼ�:%d\n",p.s[i].score[0]);
		printf("Ӣ��ɼ�:%d\n",p.s[i].score[1]);
		printf("���ĳɼ�:%d\n",p.s[i].score[2]);
		printf("��ʷ�ɼ�:%d\n",p.s[i].score[3]);
	}
}

//��ѯ:���԰�ѧ�Ż�������ѯĳ��ѧ������Ϣ
void search(studsqlist p)
{
	char search_number[11];
	printf("������Ҫ���ҵ�ѧ��ѧ��:\n");
	scanf("%s",&search_number);
	for(i=0;i<p.s_num;i++)
	{
		if(strcmp(search_number,p.s[i].no)==0)
		{
			printf("���ҵ���ѧ����Ϣ:\n");
			printf("ѧ��:%s\n",p.s[i].no);
			printf("����:%s\n",p.s[i].name);
			printf("��ѧ�ɼ�:%d\n",p.s[i].score[0]);
			printf("Ӣ��ɼ�:%d\n",p.s[i].score[1]);
			printf("���ĳɼ�:%d\n",p.s[i].score[2]);
			printf("��ʷ�ɼ�:%d\n",p.s[i].score[3]);
			break;
		}
	}
	if(i==p.s_num)
	{
		printf("δ�ҵ�ѧ��Ϊ%s��ѧ��!",search_number);
	}
}

//�޸�:�����޸�ѧ������Ϣ
void update(studsqlist *p)
{
	int j=0;
	char update_number[11];
	printf("������Ҫ�޸ĵ�ѧ��ѧ��:\n");
	scanf("%s",&update_number);
	for(i=0;i<p->s_num;i++)
	{
		if(strcmp(update_number,p->s[i].no)==0)
		{
			printf("�����������ѧ������Ϣ:\n");
			printf("ѧ��:");
			scanf("%s",&p->s[i].no);
			printf("����:");
			scanf("%s",&p->s[i].name);
			printf("��ѧ�ɼ�:");
			scanf("%d",&p->s[i].score[0]);
			printf("Ӣ��ɼ�:");
			scanf("%d",&p->s[i].score[1]);
			printf("���ĳɼ�:");
			scanf("%d",&p->s[i].score[2]);
			printf("��ʷ�ɼ�:");
			scanf("%d",&p->s[i].score[3]);
			j++;
		}
	}
	if(j==p->s_num)
	{
		printf("�����ѧ������!\n");
		update(p);
	}
}

//����:���Բ���һ��ѧ������Ϣ
void insert(studsqlist *p)
{
	char no[11];
	printf("������ָ����ѧ��ѧ��:\n");
	scanf("%s",&no);
	for(i=0;i<p->s_num;i++)
	{
		if(strcmp(no,p->s[i].no))
		{
			printf("ָ����ѧ��������!");
		}
		else
		{
			p->s[i]=p->s[i-1];
			printf("������Ҫ�����ѧ����Ϣ:\n");
			printf("ѧ��:");
			scanf("%s",&p->s[i].no);
			printf("����:");
			scanf("%s",&p->s[i].name);
			printf("��ѧ�ɼ�:");
			scanf("%d",&p->s[i].score[0]);
			printf("Ӣ��ɼ�:");
			scanf("%d",&p->s[i].score[1]);
			printf("���ĳɼ�:");
			scanf("%d",&p->s[i].score[2]);
			printf("��ʷ�ɼ�:");
			scanf("%d",&p->s[i].score[3]);
			p->s_num++;
		}
	}
}

//ɾ��:����ɾ������������ѧ����Ϣ
void del(studsqlist *p)
{
	printf("������Ҫɾ����ѧ��ѧ��:\n");
	char del_number[11];
	scanf("%s",&del_number);
	i=0;
	while(strcmp(del_number,p->s[i].no))
	{
		i++;
	}
	if(strcmp(del_number,p->s[i].no)==0)
	{
		if(i<p->s_num)
		{
			p->s[i]=p->s[i+1];
			i++;
		}
	}
	p->s_num-=1;
}

//����:���԰�ѧ�����ܳɼ�����
void sort(studsqlist p)
{
	int j;
	student temp;
	for(i=0;i<p.s_num;i++)
	{
		p.sum_score[i]=p.s[i].score[0]+p.s[i].score[1]+p.s[i].score[2]+p.s[i].score[3];
	}
	for(i=1;i<p.s_num;i++)
	{
		for(j=0;j<p.s_num-i;j++)
		{
			if(p.sum_score[j]>p.sum_score[j+1])
			{
				temp=p.s[j+1];
				p.s[j+1]=p.s[j];
				p.s[j]=temp;
			}
		}
	}
}

//���˵�������
void menu()
{
	studsqlist s;
	s.s_num=0;
	while(1)
	{
		switch(menu_select())
		{
			case 1:getchar();create(&s);system("cls");break;
			case 2:print(s);break;
			case 3:search(s);break;
			case 4:update(&s);system("cls");break;
			case 5:insert(&s);system("cls");break;
			case 6:del(&s);system("cls");break;
			case 7:sort(s);system("cls");break;
			case 8:exit(1);
		}
	}
}

//������
int main()
{
	menu();
	return 0;
}