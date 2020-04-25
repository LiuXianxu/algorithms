#include <stdio.h>
#include <math.h> 
const double PI =atan(1.0)*4;
int main(){
	int r;
	double s=0;
	scanf("%d",&r);
	s=PI*(double)r*r;
	printf("%.7f",s);
	return 0;
}
