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
	printf("gets(a)的输出：\n");
	printf("-----%s-----",b);
	printf("-----%c-----",b[3]);
	printf("\n\n");
	return 0;
} 
//gets() 可以读空格到字符数组 ，而scanf()函数中的输入"%s"格式却不可以 
