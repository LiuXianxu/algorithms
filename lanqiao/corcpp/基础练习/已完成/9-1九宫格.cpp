#include<stdio.h>
void f(int a[][3]);
int main(){
	int a[3][3];
	int i,j;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
		scanf("%d",&a[i][j]);
	}
	f(a);
	return 0;
}

void f(int a[][3]){
	int i,j;
	int n[5]={0};
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
		n[i]=n[i]+a[i][j];
		if(i==j)
		n[3]=n[3]+a[i][j];
		if(i+j==2)
		n[4]=n[4]+a[i][j];
	}
	if(n[0]==n[1]&&n[1]==n[2]&&n[2]==n[3]&&n[3]==n[4])
	printf("1");
	else 
	printf("0");	
}
