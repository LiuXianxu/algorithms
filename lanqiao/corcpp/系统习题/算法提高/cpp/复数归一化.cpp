#include<stdio.h>
#include<math.h>
typedef struct {
	float a;
	float b;
}plural;
void Normalize(plural t)
{
	float m,n;
	m=t.a/sqrt(t.a*t.a+t.b*t.b);
	n=t.b/sqrt(t.a*t.a+t.b*t.b);
	printf("%.1f+%.1fi",m,n);
}
int main(){
	plural t;
	scanf("%f%f",&t.a,&t.b);
	Normalize(t);
	return 0;
}
