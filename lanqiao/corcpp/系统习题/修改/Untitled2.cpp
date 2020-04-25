#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ok 1
  typedef struct
{
    int price;//价格
	int count[4];//折扣
	int MAXSIZE;//最大载客人数
	char Q_place[10];//起飞地
	char Z_place[10];//降落地
    char air_num[10];//航班号
	char Q_time[10];//起飞时间
	char Z_time[10];//降落时间
	int left;//余票
} plan ,*Linklist;
 typedef struct 
{
	char plan_num[10];
	char id[20];
	char name[10];
	int seat_num;
}customer,*people;

 void rplan();//录入航班信息
 void cplan();
 void xplan();
 void dticket();
 void tticket();
 plan p[1000];
   int main()
   {
	   int n;
	   do{//打印主界面
		   printf("\t欢迎使用航空客运订票系统\n");
		   printf("\t*******************************\n");
		   printf("\t==>1.录入功能==\n");
           printf("\t==>2.查询功能==\n");
		   printf("\t*******************************\n");
		   printf("\t请选择:");
		   scanf("%d",&n);
		   printf("\n");
		   setbuf(stdin,NULL);
		   switch(n)
		   {
		   case 1: rplan();
		   break;
		   case 2: cplan();
		   break;
		   default:exit(0);
		   }
	   }while(n==1||n==2||n==3||n==4||n==5);
	   return 0;

   }
   void rplan()
   {
	  
	  int i,n;
      printf("请输入需要录入的航班数\n");
      scanf("%d",&n);
	  for(i=0;i<=n;i++)
	  {
	   printf("\t请依次输入下面几项内容:\n\n");
	   printf("航班号 起点 终点 起飞时间 降落时间 航班票价 折扣 余票\n");
	   scanf("%8s%8s%8s%8s%8s%8d%8d",&p[i].air_num,&p[i].Q_place,&p[i].Z_place,&p[i].Q_time,&p[i].Z_time,&p[i].price,&p[i].count,&p[i].left);}
   }
   void cplan()
   {   
	   int n;
	   printf("\t查找航线信息\n");
	   printf("\t*****************************\n");
	   printf("\t==>目的地查询==\n");
	   printf("\t*****************************\n");
	   printf("\t请选择：");
	   scanf("%d",&n);
		   printf("\n");
   }
   void MDC()
   {
	   char s[15];
	   int m,i;
	   printf("\t请输入要查询的目的地:");
	   scanf("%8s",&s);
	   do{
		   for(i=0;i<1000;i++)
		   {
			
				if (p[i].count!=0)
			{
			   m=strcmp(p[i].Z_place,s);
			   if(m==0)
			   {
				printf("\t航班信息\n");
			    printf("\t航班号:%s\n",p[i].air_num);
                printf("\t航班票价:%d\n",p[i].price);
                printf("\t起飞时间:%s\n",p[i].Q_time);
                printf("\t降落时间:%s\n",p[i].Z_time);
                printf("\t折扣:%d\n",p[i].count);
			   }
			
		   
		   else
		   {
			   printf("\t抱歉，没有您要查找的目的地:\n\n");
			   m=0;
		   }
		   
	   }
   }
   }while(m!=0);}
