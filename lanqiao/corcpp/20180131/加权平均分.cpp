#include <stdio.h>
#include <conio.h>
int main(){
	int score;
	float credit; 
	float sum=0,cnt=0;
	freopen("C:\\Users\\�ҵĵ���\\Desktop\\input.txt","r",stdin);
	while(scanf("%d %f",&score,&credit)==2)
	{
		sum=sum+score*credit;
		cnt=cnt+credit;	
	}
	printf("ƽ���֣�%.2f\n",(float)sum/cnt);
	getch();
	return 0;
}

