#include <stdio.h>
int main(){
	void toenglish(int n);
	void currentime(int h,int m);
	int h,m;
	scanf("%d%d",&h,&m);
	currentime(h,m);
	return 0;
} 
void toenglish(int n)
{
	switch (n){
		case 0:printf("zero");break;
		case 1:printf("one");break;
		case 2:printf("two");break;
		case 3:printf("three");break;
		case 4:printf("four");break;
		case 5:printf("five");break;
		case 6:printf("six");break;
		case 7:printf("seven");break;
		case 8:printf("eight");break;
		case 9:printf("nine");break;
		case 10:printf("ten");break;
		case 11:printf("eleven");break;
		case 12:printf("twelve");break;
		case 13:printf("thirteen");break;
		case 14:printf("fourteen");break;	
		case 15:printf("fifteen");break;
		case 16:printf("sixteen");break;
		case 17:printf("seventeen");break;
		case 18:printf("eighteen");break;
		case 19:printf("nineteen");break;
		case 20:printf("twenty");break;
		case 30:printf("thirty");break;
		case 40:printf("forty");break;
		case 50:printf("fifty");break;
	}
}
void currentime(int h,int m){
	if(h<=20)
	toenglish(h);
	else
	{
		toenglish(20);
		printf(" ");
		toenglish(h%20);
	}
	printf(" ");
	if(m==0)printf("o'clock");
	else if(m<20){
		toenglish(m);
	}
	else if(m>20&&m<30){
		toenglish(20);
		printf(" ");
		toenglish(m%20);
	}
	else if(m>30&&m<40){
		toenglish(30);
		printf(" ");
		toenglish(m%30);
	}
	else if(m>40&&m<50){
		toenglish(40);
		printf(" ");
		toenglish(m%40);
	}
	else if(m>50&&m<60){
		toenglish(50);
		printf(" ");
		toenglish(m%50);
	}
	else toenglish(m);
}
