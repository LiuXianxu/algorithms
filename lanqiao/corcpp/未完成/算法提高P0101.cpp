#include <stdio.h>
#define QUALITY  (3.0*1e-23)
int main()
{
//	double quality=3.0*10e-23;
	double n;
	scanf("%lf",&n);
//	printf("%f\n",n);
	printf("%E",(n*950.0)/QUALITY);
//	printf("\n%E",QUALITY);
	return 0;	
}
