#include <stdio.h>
void Huiwen(char *p,int m)
{
	int i,z=0;
	for(i=0;i<m/2;i++)
	{
		if(p[i]!=p[m-1-i])
		{
			z++;
			break;
		}
	}
		
	if(z)
			printf("该字符串不是回文字符串!\n");
	else
			printf("该字符串为回文字符串!\n");
}
int main()
{
	int i=0;
	char string[100];
	printf("请输入一串字符，以回车为结束符:\n");
//	while((string[i]=getchar())!='\n')
//		i++;
	scanf("%s",string);
	while(string[i]!='\0')
		i++;
		printf("i=%d\n",i); 
		printf("---%c---",string[i]);
	string[i+1]='\0'; 
	printf("用户输入的字符串为：%s",string);
	Huiwen(string,i);
	return 0;
}
