#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
/*typedef struct {
	char str[100][100];
	char temp[10];
}select;*/  
  int n;
char str[100][100];
void shuchu()
{
	printf("***************************************************\n");
	printf("****************�ı��༭�ʹ�����ͳ��***************\n");
    printf("1. �����ı�\n");
    printf("2. ɾ���Ӵ�\n");
	printf("3. �������\n");
	printf("4. ����ͳ��\n");
	printf("5. �������\n");
	printf("6. �Ӵ�ͳ��\n");
	printf("7. �˳�\n");
	printf("***************************************************\n");
}
void input(char str[100][100])//�����ı�
{
	int i;
	printf("�������ı�\n");
	printf("�������ı�������\n");
	scanf("%d",&n);
	printf("�������ı����ݣ�\n");
	for(i=0;i<n;i++)
	scanf("%s",str[i]);
}
void deletezc(char str[100][100])//ɾ���Ӵ�
{
	int i,j,k;
	int t;
	int slen=0;
	int zlen=0;
	int count=0;
	int flag=1;
	char a[100];
	printf("������Ҫɾ�����Ӵ�\n");
	scanf("%s",&a);

	for(i=0;a[i];i++)
	{
		zlen++;
	}
	printf("---%d----",zlen);

	for(i=0;i<n;i++)
	{
		slen=0;
		while(str[i][slen++]);
		slen=slen-1;
		j=0;k=0;count=0;
		while(j<=slen-zlen)
		{
			if(a[k]==str[i][j])
			{
				j++;
				k++;
				count++;
			}
			else if(count==0){
				j++;
				k++;
			}
			else if(count&&count<slen)
			{
				k=0;
				count=0; 
				flag=0;
			}
			 if(count==slen)
			{
				t=j;
				for(;str[i][t];t++)
					str[i][t-zlen]=str[i][t];
					count=0;
					k=0;;
			}
			if(k==zlen)
			k=0;
		}




/*		if(strcmp(a,str[i])==0)
		{
			flag=0;
			for(j=i;j<n;j++)
			//str[i]=str[i+1];
			strcpy(str[j],str[j+1]);
		}
*/	 
		
	}	
		
	if(flag!=0)	
		printf("δ�ҵ�Ҫɾ�����Ӵ�\n");

}
void branchoutput(char str[100][100])// �������
{
	
	int i;
	printf("����ı�������Ϊ��\n");
	for(i=0;i<n;i++)
	{
		printf("%s",str[i]);
		printf("\n");
	}

}
void branchtotal()//����ͳ��
{}
void newoutput()//�������
{}
void zctotal()//�Ӵ�ͳ��
{}



int main()
{
	int x;
	shuchu();
	while(x!=7)
	{
	printf("��ѡ��Ҫ���еĲ���\n");
	scanf("%d",&x);
	switch(x)
	{
	case 1:input(str);break;
    case 2:deletezc(str);break;
	case 3:branchoutput(str);break;
	//case 4:branchtotal();break;
	//case 5:newoutput();break;
	//case 6:zctotal();break;	
	}
	}
	return 0;
}
