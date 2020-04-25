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
	printf("****************文本编辑和串查找统计***************\n");
    printf("1. 输入文本\n");
    printf("2. 删除子串\n");
	printf("3. 分行输出\n");
	printf("4. 分类统计\n");
	printf("5. 重新输出\n");
	printf("6. 子串统计\n");
	printf("7. 退出\n");
	printf("***************************************************\n");
}
void input(char str[100][100])//输入文本
{
	int i;
	printf("请输入文本\n");
	printf("请输入文本的行数\n");
	scanf("%d",&n);
	printf("请输入文本内容：\n");
	for(i=0;i<n;i++)
	scanf("%s",str[i]);
}
void deletezc(char str[100][100])//删除子串
{
	int i,j,k;
	int t;
	int slen=0;
	int zlen=0;
	int count=0;
	int flag=1;
	char a[100];
	printf("请输入要删除的子串\n");
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
		printf("未找到要删除的子串\n");

}
void branchoutput(char str[100][100])// 分行输出
{
	
	int i;
	printf("输出文本的内容为：\n");
	for(i=0;i<n;i++)
	{
		printf("%s",str[i]);
		printf("\n");
	}

}
void branchtotal()//分类统计
{}
void newoutput()//重新输出
{}
void zctotal()//子串统计
{}



int main()
{
	int x;
	shuchu();
	while(x!=7)
	{
	printf("请选择要进行的操作\n");
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
