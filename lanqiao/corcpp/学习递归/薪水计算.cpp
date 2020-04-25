#include <stdio.h>
int main()
{
	int n;
	float x,sum;
	scanf("%d",&n);
	scanf("%f",&x);
	if(n<=40)
	{
		sum=n*x;
	}
	else if(n<=50)
	{
		sum=(40+(n-40)*1.5)*x;	
	}
	else{
		sum=(40+10*1.5+(n-50)*2)*x;	
	}
	printf("%.2f",sum);
	return 0;
} 
