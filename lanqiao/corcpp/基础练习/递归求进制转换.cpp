#include <stdio.h>
#include <time.h>
void ToAnyScale(int num,int n);
void toAnyScale(int num,int n);
clock_t start,end;
double duration; 
int main()
{
	int i;
//	int num,n;
//	scanf("%d%d",&num,&n);
//	ToAnyScale(10,16);
//	printf("\n");
	start = clock();
	ToAnyScale(1000000000,2);
	end = clock();
	duration = (double)(end -start)/CLK_TCK;
	printf("\n");
	printf("%f",duration);
	printf("\n");
	start = clock();
	toAnyScale(1000000000,3);
	end = clock();
	duration = (double)(end -start)/CLK_TCK;
	printf("\n");
	printf("%f",duration);
	return 0;
} 
void ToAnyScale(int num,int n)
{
	if(num>n)
	ToAnyScale(num/n,n);
	int t;
	t=num%n;
	if(t>=10)
		printf("%c",t+'A'-10);
	else
		printf("%c",t+'0');
}
void toAnyScale(int num,int n)
{
	int t;
	t=num%n;
	if(num>n)
	ToAnyScale(num/n,n);
	if(t>=10)
		printf("%c",t+'A'-10);
	else
		printf("%c",t+'0');
}
