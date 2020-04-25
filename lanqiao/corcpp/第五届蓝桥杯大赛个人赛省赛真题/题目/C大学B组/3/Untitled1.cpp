#include <stdio.h>
#include <math.h>
int main(){
	double x;
	x=2;
	while(pow(x,x)<10){
		x=x+0.0000001;
	}
	printf("%.7lf\n",x);
	printf("%lf",x);
	return 0;
}
