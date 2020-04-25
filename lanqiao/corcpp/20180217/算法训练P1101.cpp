#include <stdio.h>
typedef struct{
	char MC[101];
	double DJ;
	int SL;
}prut;
prut SP[105];
int main(){
	int i,n;
	double sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",SP[i].MC);
		scanf("%lf",&SP[i].DJ);
		scanf("%d",&SP[i].SL);
	}
	for(i=0;i<n;i++)
	{
		sum = sum + SP[i].DJ * SP[i].SL;
	}
	printf("%lf",sum);
	return 0;
}
