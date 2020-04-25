#include <stdio.h>
void f(int *t){
	int a=10;
	int *q=&a;
	printf("传入的地址：%p\n",t);
	printf("此函数里面的地址：%p\n",q);
	t=q; //对传入地址赋值 
	printf("传入的地址被赋值后的地址：%p\n",t);

	
}
int main(){
	int a=0;
	int *p=&a;
	printf("调用函数前的地址：%p\n",p);
	printf("----------------------------\n"); 
	f(p);
	printf("----------------------------\n"); 
	printf("调用函数后的地址：%p\n",p);
	return 0;
} 
