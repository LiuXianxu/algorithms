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
	printf("��ѡ������Ҫ�ķ���\n");
	printf("*****************************\n");
	printf("************1��¼��************\n");
	printf("************2����ѯ************\n");
	printf("************3����Ʊ************\n");
	printf("************4����Ʊ************\n");
	printf("************5���޸ĺ�����Ϣ****\n");
	printf("************0���˳�************\n");
	scanf("%d",&a);
	switch(a)
	{
	case 1:
		{
			printf("��ѡ�����¼�������\n");
			entering();menu();
		   }
	case 2:
		{
		printf("��ѡ����ǲ�ѯ������\n");
		search();
		menu();
		   }
	case 3:
		{
		printf("��ѡ����Ƕ�Ʊ������\n");
		book();
		menu();
		   }
	case 4:
		{
		printf("��ѡ�������Ʊ������\n");
		tuipiao();
		menu();
		   }
	case 5:
		{
		printf("��ѡ������޸ĺ�����Ϣ������\n");
		   }
	case 0:break;
	default:printf("�������\n");system("pause");menu();
	}

}
  void entering ()
{
	FILE *fp;
	airplane s;
	fp=fopen("Flight.dat","ab");
	printf("��������Ҫ¼��ĺ������Ϣ����������š��յ�վ��  �ɻ��� ����Ʊ�� ���Ʊ����\n");
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
	 printf("�����뺽��Ż����յ�վ��\n");
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
	 else printf("�ļ������ڣ�\n");
 }

 void print(airplane s)
 {
		printf("�����Ϊ��");
		printf("%s\t",s.air_name);
		 printf("�յ�վ��Ϊ��");
		printf("%s\t",s.ter_name);
		 printf("�ɻ���Ϊ��");
		printf("%s\t",s.plane_name);
		 printf("����Ʊ��Ϊ��");
		printf("%d\t",s.sealnum);
		 printf("���Ʊ��Ϊ��");
		printf("%d\n",s.maxnum);
 }
 void print1(guest r)
 {
	 printf("�ͻ�������");
	 printf("%s\n",r.name);
	 printf("�ͻ����֤��Ϊ��");
	 printf("%s\n",r.id);
	 printf("�ͻ����������Ϊ��\n");
	 printf("%s\n",r.air_name);
	 printf("�ͻ���Ʊ����");
	 printf("%d\n",r.dp);
 }
 void book()
 {
	 FILE *fp;
	 airplane s;
     printf("����Ϊ�����������Ϣ�����Դ�Ϊ�ο���\n");
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
	else printf("�ļ������ڣ�\n");
	guest r,d;
	fp=fopen("guest.dat","ab+");	
	printf("��������Ҫ¼��Ķ�Ʊ�˵���Ϣ��������Ʊ�����������֤�š��������ຽ��š���Ʊ����\n");
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
					printf("���д�����Ϣ��");
				else 
				fread(&d,sizeof(guest),1,fp);
			}
			fwrite(&r,sizeof(airplane),1,fp);
			printf("��Ʊ�ɹ���");
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
	 printf("����������Ʊ���˵����֤�ţ�");
	 scanf("%s",&r1.id);
	 setbuf(stdin,NULL);
	 if(fp)
	 {
	 	fread(&r2,sizeof(guest),1,fp);
	 	printf("�򿪳ɹ���\n");
		// printf("asdads");
		while(!feof(fp))
		{
		
			printf("����ѭ����"); 
			if(strcmp(r1.id,r2.id)==0)
			{
				printf("�Ƚϳɹ���\n");
				//printf("asdads");
				print1(r2); 
				flag=1;
				printf("��������Ҫ����һ�������Ʊ,�����뺽��ź���Ʊ����\n");
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
				printf("��Ʊ�ɹ���\n");
			}
			else 
				printf("�ļ�������1��\n");
			}
			fread(&r2,sizeof(guest),1,fp);
		 }
		 fclose(fp);
		 if(flag)printf("û���ҵ��ͻ���Ϣ!\n");
	 }
	 else printf("�ļ������ڣ�\n");
 }
 void xiugai()
 {
	 int i;
	 FILE *fp;
	 airplane info,a2,s;
	 printf("��������Ҫ�޸ĵĺ���ĺ���Ž��м�����");
	 scanf("%s",info.air_name);
	 if(fp)
	 {
			fread(&s,sizeof(airplane),0,fp);
		while(!feof(fp))
		{
			if(strcmp(info.air_name,s.air_name)==0||strcmp(info.air_name,s.ter_name)==0)
			{
				printf("��������Ҫ�޸ĵ���Ϣ��\n");
				printf("�յ�վ���޸�Ϊ��");
				scanf("%s",a2.ter_name);
				printf("�ɻ����޸�Ϊ��");
				scanf("%s",a2.plane_name);
				printf("���۳�Ʊ���޸�Ϊ��");
				scanf("%s",a2.sealnum);
				printf("���Ʊ���޸�Ϊ��");
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
	 else printf("�ļ������ڣ�\n");
 }
