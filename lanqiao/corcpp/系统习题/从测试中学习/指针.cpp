#include <stdio.h>
void f(int *t){
	int a=10;
	int *q=&a;
	printf("����ĵ�ַ��%p\n",t);
	printf("�˺�������ĵ�ַ��%p\n",q);
	t=q; //�Դ����ַ��ֵ 
	printf("����ĵ�ַ����ֵ��ĵ�ַ��%p\n",t);

	
}
int main(){
	int a=0;
	int *p=&a;
	printf("���ú���ǰ�ĵ�ַ��%p\n",p);
	printf("----------------------------\n"); 
	f(p);
	printf("----------------------------\n"); 
	printf("���ú�����ĵ�ַ��%p\n",p);
	return 0;
} 
