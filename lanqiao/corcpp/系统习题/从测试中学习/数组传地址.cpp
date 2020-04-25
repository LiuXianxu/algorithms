#include <stdio.h>
char a[100]={'\0'};
double num[100];
void address(double num[])
{
	printf("%d\n",sizeof(num));
}
void address()
{
	printf("%d\n",sizeof(num));
}
void print(char a[]){
	printf("%d\n",sizeof(a));
}
int main(){
	//char a[100]={'\0'};
	int i=0;
	scanf("%s",a);
	address(); 
	address(num);
	printf("%d\n",sizeof(num));	
	printf("%d\n",sizeof(a));
	for(i=0;a[i];i++)
		printf("%c",a[i]);
	printf("%c\n",a[i+1]);
	print(a);
	return 0;
} 
