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
		a[i]=a[len-i-1];//ע���һ����Ȼ��һ '\0'��ͷ���޷��� "%s"���
		a[len-i-1]=ch;
	}
	printf("��ת��%s\n",a);
	printf("----------------\n");
	for(i=0;i<len;i++)
	printf("%c",a[i]);
	
	return 0;
}
