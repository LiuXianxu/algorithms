#include <stdio.h>
#include <conio.h>
//#include <stdlib.h>
int main(){
	int score;
	int sum=0,cnt=0;
	freopen("C:\\Users\\�ҵĵ���\\Desktop\\input.txt","r",stdin);
	while(scanf("%d",&score)==1)
	{
		sum=sum+score;
		cnt++;	
	}
//	printf("%f\n",(float)(1/3));
//	printf("%f\n",(float)1/3);
	printf("ƽ���֣�%.2f\n",(float)sum/cnt);
	getch();
	return 0;
}

