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
			printf("���ַ������ǻ����ַ���!\n");
	else
			printf("���ַ���Ϊ�����ַ���!\n");
}
int main()
{
	int i=0;
	char string[100];
	printf("������һ���ַ����Իس�Ϊ������:\n");
//	while((string[i]=getchar())!='\n')
//		i++;
	scanf("%s",string);
	while(string[i]!='\0')
		i++;
		printf("i=%d\n",i); 
		printf("---%c---",string[i]);
	string[i+1]='\0'; 
	printf("�û�������ַ���Ϊ��%s",string);
	Huiwen(string,i);
	return 0;
}
