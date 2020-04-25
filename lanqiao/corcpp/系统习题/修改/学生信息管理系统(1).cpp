/*任务:定义一个学生类型student(学号,姓名,四门课程成绩),学生顺序表studsqlist,含有学生数组和学生数。
  通过该系统可以实现如下功能:
  录入:输入每位学生的信息;
  输出:输出每位学生的信息;
  查询:可以按学号或姓名查询某个学生的信息;
  修改:可以修改学生的信息;
  插入:可以插入一个学生的信息;
  删除:可以删除满足条件的学生信息;
  排序:可以按学生的总成绩排序。
*/      
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 1000
typedef struct
{
	char no[11];//学号
	char name[15];//姓名
	int score[4];//各科分数
}student;
typedef struct
{
	student s[MAXSIZE];//学生数组
	int sum_score[MAXSIZE];//总分数组
	int s_num;//总人数
}studsqlist;
int i;

//菜单选择栏
int menu_select()
{
	int choice;
	printf("**********************学生信息管理系统********************\n");
	printf("                         1  录入                          \n");
	printf("                         2  输出                          \n");
	printf("                         3  查询                          \n");
	printf("                         4  修改                          \n");
	printf("                         5  插入                          \n");
	printf("                         6  删除                          \n");
	printf("                         7  排序                          \n");
	printf("                         8  退出                          \n");
	printf("请输入您的选择(1-8)");
	scanf("%d",&choice);
	return choice;
}

//录入:输入每位学生的信息
void create(studsqlist *p)
{
	p->s_num=0;
	printf("是否开始录入学生信息?请输入一个字符:(Y表示yes,N表示no)\n");
	char ch;
	i=0;
	scanf("%c",&ch);
	while(ch=='Y')
	{
		printf("请输入学生的信息:\n");
		printf("学号:");
		scanf("%s",&p->s[i].no);
		printf("姓名:");
		scanf("%s",&p->s[i].name);
		printf("数学成绩:");
		scanf("%d",&p->s[i].score[0]);
		printf("英语成绩:");
		scanf("%d",&p->s[i].score[1]);
		printf("语文成绩:");
		scanf("%d",&p->s[i].score[2]);
		printf("历史成绩:");
		scanf("%d",&p->s[i].score[3]);
		p->s_num++;
		i++;
		ch=NULL;
		getchar();
		printf("是否开始录入学生信息?请输入一个字符:(Y表示yes,N表示no)\n");
		scanf("%c",&ch);
	}
	if(ch!='Y')
	{
		printf("您已退出录入信息操作!\n");
	}
}

//输出:输出每位学生的信息
void print(studsqlist p)
{
	for(i=0;i<p.s_num;i++)
	{
		printf("学号:%s\n",p.s[i].no);
		printf("姓名:%s\n",p.s[i].name);
		printf("数学成绩:%d\n",p.s[i].score[0]);
		printf("英语成绩:%d\n",p.s[i].score[1]);
		printf("语文成绩:%d\n",p.s[i].score[2]);
		printf("历史成绩:%d\n",p.s[i].score[3]);
	}
}

//查询:可以按学号或姓名查询某个学生的信息
void search(studsqlist p)
{
	char search_number[11];
	printf("请输入要查找的学生学号:\n");
	scanf("%s",&search_number);
	for(i=0;i<p.s_num;i++)
	{
		if(strcmp(search_number,p.s[i].no)==0)
		{
			printf("查找到的学生信息:\n");
			printf("学号:%s\n",p.s[i].no);
			printf("姓名:%s\n",p.s[i].name);
			printf("数学成绩:%d\n",p.s[i].score[0]);
			printf("英语成绩:%d\n",p.s[i].score[1]);
			printf("语文成绩:%d\n",p.s[i].score[2]);
			printf("历史成绩:%d\n",p.s[i].score[3]);
			break;
		}
	}
	if(i==p.s_num)
	{
		printf("未找到学号为%s的学生!",search_number);
	}
}

//修改:可以修改学生的信息
void update(studsqlist *p)
{
	int j=0;
	char update_number[11];
	printf("请输入要修改的学生学号:\n");
	scanf("%s",&update_number);
	for(i=0;i<p->s_num;i++)
	{
		if(strcmp(update_number,p->s[i].no)==0)
		{
			printf("请重新输入该学生的信息:\n");
			printf("学号:");
			scanf("%s",&p->s[i].no);
			printf("姓名:");
			scanf("%s",&p->s[i].name);
			printf("数学成绩:");
			scanf("%d",&p->s[i].score[0]);
			printf("英语成绩:");
			scanf("%d",&p->s[i].score[1]);
			printf("语文成绩:");
			scanf("%d",&p->s[i].score[2]);
			printf("历史成绩:");
			scanf("%d",&p->s[i].score[3]);
			j++;
		}
	}
	if(j==p->s_num)
	{
		printf("输入的学号有误!\n");
		update(p);
	}
}

//插入:可以插入一个学生的信息
void insert(studsqlist *p)
{
	char no[11];
	printf("请输入指定的学生学号:\n");
	scanf("%s",&no);
	for(i=0;i<p->s_num;i++)
	{
		if(strcmp(no,p->s[i].no))
		{
			printf("指定的学生不存在!");
		}
		else
		{
			p->s[i]=p->s[i-1];
			printf("请输入要插入的学生信息:\n");
			printf("学号:");
			scanf("%s",&p->s[i].no);
			printf("姓名:");
			scanf("%s",&p->s[i].name);
			printf("数学成绩:");
			scanf("%d",&p->s[i].score[0]);
			printf("英语成绩:");
			scanf("%d",&p->s[i].score[1]);
			printf("语文成绩:");
			scanf("%d",&p->s[i].score[2]);
			printf("历史成绩:");
			scanf("%d",&p->s[i].score[3]);
			p->s_num++;
		}
	}
}

//删除:可以删除满足条件的学生信息
void del(studsqlist *p)
{
	printf("请输入要删除的学生学号:\n");
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

//排序:可以按学生的总成绩排序
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

//主菜单功能栏
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

//主函数
int main()
{
	menu();
	return 0;
}