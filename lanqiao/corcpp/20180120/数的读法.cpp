#include <stdio.h>
int readthousand(int n,int y);
void toprint(int n);
int main(){
	int n,x,y=0;
	scanf("%d",&n);
	if(n)
	{
		x=n/100000000;
		if(readthousand(x,y))
		{
			printf("yi ");
			y=1;
		}
		x=n%100000000/10000;
		if(readthousand(x,y))
		{
			printf("wan ");
			y=1;
		}
		else y=0;
		x=n%10000;
		readthousand(x,y);
	
	}
	else {
		printf("ling");
	}
	
	return 0;
} 
int readthousand(int n,int y)
{
	int a,t=0;
	a=n/1000;
	if(n!=0&&n<1000&&y==1)
		printf("ling ");
	if(a!=0)
	{
		toprint(a);
		printf("qian ");
		t=1;
	}
	a=n%1000/100;
	if(a!=0)
	{
		toprint(a);
		printf("bai ");
		t=2;	
	}
	a=n%100/10;
	if(a!=0){
		if(t==1)printf("ling ");
		if(t==0&&a==1&&y!=1);
		else toprint(a);
		printf("shi ");
		t=3;
	}
	a=n%10;
	if(a!=0){
		if(t==1||t==2)printf("ling ");
		toprint(a);
	}
	if(n!=0)return 1;
	else return 0;	
}
void toprint(int n)
{
	switch(n)
	{
		case 1 : printf("yi ");break;
		case 2 : printf("er ");break;
		case 3 : printf("san ");break;
		case 4 : printf("si ");break;
		case 5 : printf("wu ");break;
		case 6 : printf("liu ");break;
		case 7 : printf("qi ");break;
		case 8 : printf("ba ");break;
		case 9 : printf("jiu ");break;
		case 10 : printf("shi ");break;
	}
} 
