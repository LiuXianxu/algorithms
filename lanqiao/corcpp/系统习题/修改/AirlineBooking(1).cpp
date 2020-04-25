#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 1
typedef struct airline
{
	char air_name[10];
	char ter_name[10];
	char plane_name[10];
	int sealnum;
	int maxnum;
}airplane;
typedef struct 
{
	char name[20];
	char id[20];
	char air_name[10];
	int dp;
}guest;
void menu();
void entering ();
void search();
void book();
void print(airplane s);
 void tuipiao();
  void print1(guest r);
int main()
{
	menu();
	return 0;
}
void menu()
{
	int a;
	printf("请选择您需要的服务：\n");
	printf("*****************************\n");
	printf("************1、录入************\n");
	printf("************2、查询************\n");
	printf("************3、订票************\n");
	printf("************4、退票************\n");
	printf("************5、修改航班信息****\n");
	printf("************0、退出************\n");
	scanf("%d",&a);
	switch(a)
	{
	case 1:
		{
			printf("您选择的是录入操作：\n");
			entering();menu();
		   }
	case 2:
		{
		printf("您选择的是查询操作：\n");
		search();
		menu();
		   }
	case 3:
		{
		printf("您选择的是订票操作：\n");
		book();
		menu();
		   }
	case 4:
		{
		printf("您选择的是退票操作：\n");
		tuipiao();
		menu();
		   }
	case 5:
		{
		printf("您选择的是修改航班信息操作：\n");
		   }
	case 0:break;
	default:printf("输入错误！\n");system("pause");menu();
	}

}
  void entering ()
{
	FILE *fp;
	airplane s;
	fp=fopen("Flight.dat","ab");
	printf("请输入你要录入的航班的信息（包括航班号、终点站名  飞机号 已售票数 最大票数）\n");
		scanf("%s",&s.air_name);
		scanf("%s",&s.ter_name);
		scanf("%s",&s.plane_name);
		scanf("%d",&s.sealnum);
		scanf("%d",&s.maxnum);
		if(fp)
		{
			fwrite(&s,sizeof(airplane),1,fp);
		}
	fclose(fp);
}
 void search()
 {
	 FILE *fp;
	 airplane s;
	 char info[10];
	 fp=fopen("Flight.dat","rb");
	 printf("请输入航班号或者终点站名\n");
	 scanf("%s",info);
	if(fp){
			fread(&s,sizeof(airplane),1,fp);
		while(!feof(fp))
		{
			if(strcmp(info,s.air_name)==0||strcmp(info,s.ter_name)==0)
			{
				print(s);
			}
			fread(&s,sizeof(airplane),1,fp);
		 }
		 fclose(fp);
	 }
	 else printf("文件不存在！\n");
 }

 void print(airplane s)
 {
		printf("航班号为：");
		printf("%s\t",s.air_name);
		 printf("终点站名为：");
		printf("%s\t",s.ter_name);
		 printf("飞机号为：");
		printf("%s\t",s.plane_name);
		 printf("已售票量为：");
		printf("%d\t",s.sealnum);
		 printf("最大票量为：");
		printf("%d\n",s.maxnum);
 }
 void print1(guest r)
 {
	 printf("客户姓名：");
	 printf("%s\n",r.name);
	 printf("客户身份证号为：");
	 printf("%s\n",r.id);
	 printf("客户所定航班号为：\n");
	 printf("%s\n",r.air_name);
	 printf("客户订票量：");
	 printf("%d\n",r.dp);
 }
 void book()
 {
	 FILE *fp;
	 airplane s;
     printf("以下为各个航班的信息，请以此为参考：\n");
	 fp=fopen("Flight.dat","rb");
	 if(fp)
	 {
		fread(&s,sizeof(airplane),1,fp);
		while(!feof(fp))
		{
			print(s);
			fread(&s,sizeof(airplane),1,fp);
		}
		fclose(fp);
	 }
	else printf("文件不存在！\n");
	guest r,d;
	fp=fopen("guest.dat","ab+");	
	printf("请输入你要录入的订票人的信息（包括订票人姓名、身份证号、所定航班航班号、订票量）\n");
	scanf("%s",&r.name);
	setbuf(stdin,NULL);
	scanf("%s",&r.id);
	setbuf(stdin,NULL);
	scanf("%s",&r.air_name);
	setbuf(stdin,NULL);
	scanf("%d",&r.dp);
	setbuf(stdin,NULL);
	if(fp)
	{
			fread(&d,sizeof(guest),1,fp);
			while(!feof(fp))
			{
			
				if(strcmp(d.id,r.id)==0)
					printf("已有此人信息！");
				else 
				fread(&d,sizeof(guest),1,fp);
			}
			fwrite(&r,sizeof(airplane),1,fp);
			printf("订票成功！");
			fclose(fp);	
	}
	fp=fopen("Flight.dat","rb+");
	if(fp)
	{
		fread(&s,sizeof(airplane),1,fp);
		while(!feof(fp))
		{
			if(strcmp(s.air_name,r.air_name)==0)
			{
				s.sealnum=s.sealnum+r.dp;
				fseek(fp,-(long)sizeof(airplane),1);
				fwrite(&s,sizeof(airplane),1,fp);
				break;
			}
			fread(&s,sizeof(airplane),1,fp);
		}
		fclose(fp);
	}

 }
	
 void tuipiao()
 {
	 int n;
	 guest r1,r2;
	 airplane a1,a2;
	 int flag=0;
	 FILE *fp,*fp1;
	 fp=fopen("guest.dat","rb+");
	 printf("请输入你退票的人的身份证号：");
	 scanf("%s",&r1.id);
	 setbuf(stdin,NULL);
	 if(fp)
	 {
	 	fread(&r2,sizeof(guest),1,fp);
	 	printf("打开成功！\n");
		// printf("asdads");
		while(!feof(fp))
		{
		
			printf("进入循环！"); 
			if(strcmp(r1.id,r2.id)==0)
			{
				printf("比较成功！\n");
				//printf("asdads");
				print1(r2); 
				flag=1;
				printf("请问您需要退哪一个航班的票,请输入航班号和退票数量\n");
				scanf("%s",a1.air_name);
				scanf("%d",&n);
				fp1=fopen("Flight.dat","rb+");
				if(fp1)
				{
					fread(&a2,sizeof(airplane),1,fp1);
					while(!feof(fp1))
					{
						if(strcmp(a1.air_name,a2.air_name)==0)
						{
							a2.sealnum=a2.sealnum-n;
							fseek(fp1,-(long)sizeof(airplane),1);
							fwrite(&a2,sizeof(airplane),1,fp1);
							break;
						}
						fread(&a2,sizeof(airplane),1,fp1);
				 }
				fclose(fp1);
				printf("退票成功！\n");
			}
			else 
				printf("文件不存在1！\n");
			}
			fread(&r2,sizeof(guest),1,fp);
		 }
		 fclose(fp);
		 if(flag)printf("没有找到客户信息!\n");
	 }
	 else printf("文件不存在！\n");
 }
 void xiugai()
 {
	 int i;
	 FILE *fp;
	 airplane info,a2,s;
	 printf("请输入你要修改的航班的航班号进行检索：");
	 scanf("%s",info.air_name);
	 if(fp)
	 {
			fread(&s,sizeof(airplane),0,fp);
		while(!feof(fp))
		{
			if(strcmp(info.air_name,s.air_name)==0||strcmp(info.air_name,s.ter_name)==0)
			{
				printf("请输入你要修改的信息：\n");
				printf("终点站名修改为：");
				scanf("%s",a2.ter_name);
				printf("飞机号修改为：");
				scanf("%s",a2.plane_name);
				printf("已售出票数修改为：");
				scanf("%s",a2.sealnum);
				printf("最大票数修改为：");
				scanf("%s",a2.maxnum);
				for(i=0;i<10;i++)
				{
					s.ter_name[i]=a2.ter_name[i];
					s.plane_name[i]=a2.plane_name[i];
				}
				s.sealnum=a2.sealnum;
				s.maxnum=a2.maxnum;
			}
			fread(&s,sizeof(airplane),1,fp);
		 }
		 fclose(fp);
	 }
	 else printf("文件不存在！\n");
 }
