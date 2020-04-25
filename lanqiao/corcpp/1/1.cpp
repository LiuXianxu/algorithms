#include <stdio.h>
int main()
{
	float p,d;
	float sum=0;
	freopen("C:\\in.txt","r",stdin);
	while(scanf("%f %f",&p,&d)==2)
	{
		
		printf("%f %f\n",p,d);
		sum = sum + p*d;
	}
	
	printf("%f",sum);
}
