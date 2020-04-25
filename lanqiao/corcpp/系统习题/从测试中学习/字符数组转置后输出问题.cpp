#include <stdio.h>
int main(){
	int len=-1,i;
	char ch;
	char a[10]={'\0'}; 
	scanf("%s",a);
	while(a[++len]);
	printf("%d\n",len);
	printf("%s\n",a);
	for(i=0;i<len/2;i++)
	{
		ch=a[i];
		a[i]=a[len-i-1];//注意减一，不然会一 '\0'开头，无法用 "%s"输出
		a[len-i-1]=ch;
	}
	printf("反转后：%s\n",a);
	printf("----------------\n");
	for(i=0;i<len;i++)
	printf("%c",a[i]);
	
	return 0;
}
