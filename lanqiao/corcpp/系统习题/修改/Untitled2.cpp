#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ok 1
  typedef struct
{
    int price;//�۸�
	int count[4];//�ۿ�
	int MAXSIZE;//����ؿ�����
	char Q_place[10];//��ɵ�
	char Z_place[10];//�����
    char air_num[10];//�����
	char Q_time[10];//���ʱ��
	char Z_time[10];//����ʱ��
	int left;//��Ʊ
} plan ,*Linklist;
 typedef struct 
{
	char plan_num[10];
	char id[20];
	char name[10];
	int seat_num;
}customer,*people;

 void rplan();//¼�뺽����Ϣ
 void cplan();
 void xplan();
 void dticket();
 void tticket();
 plan p[1000];
   int main()
   {
	   int n;
	   do{//��ӡ������
		   printf("\t��ӭʹ�ú��տ��˶�Ʊϵͳ\n");
		   printf("\t*******************************\n");
		   printf("\t==>1.¼�빦��==\n");
           printf("\t==>2.��ѯ����==\n");
		   printf("\t*******************************\n");
		   printf("\t��ѡ��:");
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
      printf("��������Ҫ¼��ĺ�����\n");
      scanf("%d",&n);
	  for(i=0;i<=n;i++)
	  {
	   printf("\t�������������漸������:\n\n");
	   printf("����� ��� �յ� ���ʱ�� ����ʱ�� ����Ʊ�� �ۿ� ��Ʊ\n");
	   scanf("%8s%8s%8s%8s%8s%8d%8d",&p[i].air_num,&p[i].Q_place,&p[i].Z_place,&p[i].Q_time,&p[i].Z_time,&p[i].price,&p[i].count,&p[i].left);}
   }
   void cplan()
   {   
	   int n;
	   printf("\t���Һ�����Ϣ\n");
	   printf("\t*****************************\n");
	   printf("\t==>Ŀ�ĵز�ѯ==\n");
	   printf("\t*****************************\n");
	   printf("\t��ѡ��");
	   scanf("%d",&n);
		   printf("\n");
   }
   void MDC()
   {
	   char s[15];
	   int m,i;
	   printf("\t������Ҫ��ѯ��Ŀ�ĵ�:");
	   scanf("%8s",&s);
	   do{
		   for(i=0;i<1000;i++)
		   {
			
				if (p[i].count!=0)
			{
			   m=strcmp(p[i].Z_place,s);
			   if(m==0)
			   {
				printf("\t������Ϣ\n");
			    printf("\t�����:%s\n",p[i].air_num);
                printf("\t����Ʊ��:%d\n",p[i].price);
                printf("\t���ʱ��:%s\n",p[i].Q_time);
                printf("\t����ʱ��:%s\n",p[i].Z_time);
                printf("\t�ۿ�:%d\n",p[i].count);
			   }
			
		   
		   else
		   {
			   printf("\t��Ǹ��û����Ҫ���ҵ�Ŀ�ĵ�:\n\n");
			   m=0;
		   }
		   
	   }
   }
   }while(m!=0);}
