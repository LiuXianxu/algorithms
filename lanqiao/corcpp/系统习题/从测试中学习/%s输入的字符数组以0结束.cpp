#include<stdio.h>
int main(){
	int i=0;
	char a[10];
	char b[10]; 
	gets(b);
	scanf("%s",a);
	while(a[i]!='\0'){
		printf("-----%c-----",a[i++]);
	}
	printf("%c",a[i]); 
	printf("-----%s-----\n",a);
	printf("gets(a)�������\n");
	printf("-----%s-----",b);
	printf("-----%c-----",b[3]);
	printf("\n\n");
	return 0;
} 
//gets() ���Զ��ո��ַ����� ����scanf()�����е�����"%s"��ʽȴ������ 
