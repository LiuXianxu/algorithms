 #include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef struct Student
{
    int id;/*学生学号*/
    char name[20];/*学生姓名*/
    char sex[10];/*性别*/
    float score1;/*平时成绩*/
    float score2;/*实验成绩*/
    float score3;/*期末成绩*/
	float score4;/*总成绩*/
    struct Student *next;/*指向下一个节点的指针*/
}Stu;

int iCount;
Stu *pMain=NULL;

void menu(); 
Stu *Create();
void printAll(Stu *head);
Stu *find(Stu *,int);
void print(Stu *Stu);
void modify(Stu *,int);
Stu *delet(Stu *,int);
Stu *insert(Stu *head,int id);
Stu *sort(Stu *head);
//void count(float score1,float score2,float score3,float score4);/*统计*/

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choice;
    int id;
    printf("\n\n");
    printf("\t------------------------------------\n");
    printf("\t|     欢迎使用学生信息管理系统     |\n");
    printf("\t------------------------------------\n");
    printf("\t|          1-录入学生信息          |\n");
    printf("\t|          2-查询学生信息          |\n");
    printf("\t|          3-修改学生信息          |\n");
    printf("\t|          4-删除学生信息          |\n");
    printf("\t|          5-显示所有学生          |\n");
    printf("\t|          6-学生成绩排序          |\n");
	printf("\t|          7-插入学生信息          |\n");
    printf("\t|          8-  退出程序            |\n");
    printf("\t请选择功能 1-8 ：");
    scanf("%d",&choice);
    getchar();
    system("cls");
    switch(choice)
    {
        case 1:
            pMain=Create(); 
            if(pMain==NULL)
                printf("\t录入出错了 =、=\n");
            else
            {
                system("cls");
                printf("\t成功录入%d个学生信息\n",iCount);
            } 
            menu();
            break;
        case 2:
            if(pMain==NULL)
            {
                printf("\t没有任何学生可供查询\n");
            }
            else
            {
                printf("\t输入查询的id：");
                scanf("%d",&id);
                print(find(pMain,id));
            }
            menu();
            break;
        case 3:
            if(pMain==NULL)
            {
                printf("\t没有任何学生可供修改\n");
            }
            else
            {
                printf("\t输入修改的id：");
                scanf("%d",&id);
                modify(pMain,id);
                system("cls");
                printf("\t修改成功\n");
            }
            menu();
            break;
        case 4:
            if(pMain==NULL)
            {
                printf("\t没有任何学生可供删除\n");
            }
            else
            {
                printf("\t输入删除的id：");
                scanf("%d",&id);
                pMain=delet(pMain,id); 
                system("cls");
                printf("\t删除成功\n");
            }
            menu();
            break;
        case 5:
            if(pMain==NULL)
            {
                printf("\t没有任何学生可供显示\n");
            }
            else
                printAll(pMain);
			menu();
            break;
        case 6:
            printf("\t按总评成绩排序\n\n");
			sort(pMain);
			printAll(pMain);
            menu();
            break;
		case 7:
			if(pMain==NULL)
            {
                printf("\t没有位置可供插入\n");
            }
            else
            {
			printf("\t请输入所插入的位置\n");
			scanf("%d",&id);
			insert(pMain,id);
			system("cls");
			printf("\t插入成功\n");
			}
			menu();
			break;
        case 8:
            exit(0);
            break;
        default:
            menu();
            break;
    }
}

Stu *Create()
{
    int flag=1;
   Stu *pNew,*pEnd,*pHead;
	pHead=pEnd=NULL;
    iCount=0;
    while(flag==1)
    {
		pNew=(Stu *)malloc(sizeof(Stu));
        printf("\t请输入学生学号：");
        scanf("%d",&pNew->id);
        printf("\t请输入学生姓名：");
        scanf("%s",pNew->name);
        printf("\t请输入学生性别：");
        scanf("%s",pNew->sex);
        printf("\t请输入平时成绩：");
        scanf("%f",&pNew->score1);
        printf("\t请输入实验成绩：");
        scanf("%f",&pNew->score2);
        printf("\t请输入期末成绩：");
        scanf("%f",&pNew->score3);
        printf("\n");
        iCount++;
        if(iCount==1)
        {
            pHead=pNew;
        }
        else
        {
            pEnd->next=pNew;
        }
		pEnd=pNew;
		printf("\t是否继续输入(1继续，其它则退出并返回主菜单):");
        scanf("%d",&flag);
        //pNew=(Stu *)malloc(sizeof(Stu));
    }
	pEnd->next=NULL;
	pNew=(Stu *)malloc(sizeof(Stu));
	pNew->next=pHead;
	pHead=pNew;
    return(pHead);
}

void printAll(Stu *head)
{
    Stu *p=head->next;
    if(p)/*链表不为空时才输出表头*/ 
    {
        printf("学号    姓名    性别    平时成绩        实验成绩        期末成绩     总评成绩\n");
        printf("--------------------------------------------------------------------------------\n");
    }

    while(p)/*遍历链表，输出每个结点的信息*/
    {
		p->score4=p->score1*2/5+p->score2*3/10+p->score3*3/10;
        printf("%d\t%s\t%s\t%f\t%f\t%f      %f\n",p->id,p->name,p->sex,p->score1,p->score2,p->score3,p->score4);
        p=p->next;
    }
}


Stu *find(Stu *head,int id)
{
	int j=1;
    Stu *p=head->next;
	if(p->id<1) return NULL;
    while(p&&p->id!=id)
	{/*如果p不为空并且p不是要找的结点*/ 
        p=p->next;
		j++;
	}/*令p指向下一个结点*/ 
    return p;
}

Stu *insert(Stu *head,int id)
{
	Stu *p,*q;
	q=find(head,id);
	if(!q&&p->id!=0)
		printf("\n找不到第%d个学生，不能插入!",p->id);
	else
	{
		p=(Stu*)malloc(sizeof(Stu));
		printf("\t请输入学生学号：");
        scanf("%d",&p->id);
        printf("\t请输入学生姓名：");
        scanf("%s",p->name);
        printf("\t请输入学生性别：");
        scanf("%s",p->sex);
        printf("\t请输入平时成绩：");
        scanf("%f",&p->score1);
        printf("\t请输入实验成绩：");
        scanf("%f",&p->score2);
        printf("\t请输入期末成绩：");
		scanf("%f",&p->score3);
		if(p->id==0){
			p->next=head->next;
			head->next=p;
		}
		else{
			p->next=q->next;
			q->next=p;
		}
		iCount++;
	}
	return head;
}

Stu *sort(Stu *head)
{ 
	Stu *q,*p,*t1,*t2;
	p=head->next;
	while(p)
	{
		p->score4=p->score1*2/5+p->score2*3/10+p->score3*3/10;
		p=p->next;
	}
	
		for(q=head;q->next!=NULL;q=q->next)
			for(p=q->next;p->next!=NULL;p=p->next) 
			{ 
				
				if(q->next->score4>p->next->score4) 
				{ 
					if(q->next==p)  
					{ 
						t1=p->next;  
						p->next=p->next->next; 
						t1->next=q->next; 
						q->next=t1; 
						p=t1; 
					} 
					else 
					{  
						t1=p->next;  
						t2=q->next;  
						p->next=p->next->next; 
						q->next=q->next->next; 
						t1->next=q->next; 
						q->next=t1; 
						t2->next=p->next; 
						p->next=t2; 
 
					}  
 
				}  

			}  
	return head;
}

void print(Stu *s)
{
    if(!s)/*如果指针为空，即不存在该结点*/ 
        printf("\t%s\n","没有查询到该学生的信息，请检查输入");
    else/*若指针不为空则输出学生信息*/ 
    {
		s->score4=s->score1*2/5+s->score2*3/10+s->score3*3/10;
        printf("学号    姓名    性别    平时成绩        实验成绩        期末成绩       总评成绩\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("%d\t%s\t%s\t%f\t%f\t%f\t%f\n",s->id,s->name,s->sex,s->score1,s->score2,s->score3,s->score4);
    }
}

void modify(Stu *head,int id)
{
    Stu *p=find(head,id);/*首先查找该id的学生，将结果保存在p中*/ 
    if(p)/*如果查找到学生，则可以修改*/ 
    {
        printf("\t======================================================\n");
        printf("\t               ***** 修改学生信息 *****               \n");
        printf("\t======================================================\n");
        printf("该学生的信息如下：\n");
        print(p);
        printf("\t请输入影学生编号：");
        scanf("%d",&p->id);
        printf("\t请输入学生名称：");
        scanf("%s",p->name);
        printf("\t请输入学生性别：");
        scanf("%s",&p->sex);
        printf("\t请输入平时成绩：");
        scanf("%f",&p->score1);
        printf("\t请输入实验成绩：");
        scanf("%f",&p->score2);
        printf("\t请输入期末成绩：");
        scanf("%f",&p->score3);
    }
    else
        printf("\t未查询到该学生的信息，请检查输入.\n");
}

Stu *delet(Stu *head,int id)
{
    Stu *q=NULL,*p=head->next;
	while(p&&p->id!=id)
    {
		q=p;
		p=p->next;
	}
	if(p)
	{
		if(!q) head->next=head->next->next;
		else q->next=p->next;
	}
	iCount--;
	return head;
}
