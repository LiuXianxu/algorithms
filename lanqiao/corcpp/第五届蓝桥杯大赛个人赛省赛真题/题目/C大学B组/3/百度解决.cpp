#include <stdio.h>
#include <math.h> 
int main(){
	double x;
	x=2.0;
	while(x<3.0){
		x=x+0.0000001;
		if(fabs(pow(x,x)-10.0)<0.000001){
			printf("%lf\n",x);
				printf("%.7lf\n",x);
				break;
		}
	}
	return 0;
}
