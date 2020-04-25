#include <stdio.h>
#include <math.h>
typedef struct
{
	double x;
	double y;
}point;
typedef struct
{
	point A;
	point B;
	point C;
}triangle;
double C(triangle t);
double S(triangle t);
point G(triangle t);
point circumcenter(triangle t);
int main()
{
	triangle s;
	point t;
	scanf("%lf%lf",&s.A.x,&s.A.y);
	scanf("%lf%lf",&s.B.x,&s.B.y);
	scanf("%lf%lf",&s.C.x,&s.C.y);
	printf("%.2lf\n",C(s));
	printf("%.2lf\n",S(s));
	t=circumcenter(s);
	printf("%.2lf %.2lf\n",t.x,t.y);
	t=G(s);
	printf("%.2lf %.2lf\n",t.x,t.y);
	return 0;
}
double C(triangle t)
{
	double a,b,c;
	a=sqrt((t.A.x-t.B.x)*(t.A.x-t.B.x)+(t.A.y-t.B.y)*(t.A.y-t.B.y));
	b=sqrt((t.A.x-t.C.x)*(t.A.x-t.C.x)+(t.A.y-t.C.y)*(t.A.y-t.C.y));
	c=sqrt((t.C.x-t.B.x)*(t.C.x-t.B.x)+(t.C.y-t.B.y)*(t.C.y-t.B.y));
	return a+b+c;
}
double S(triangle t){
	double a,b,c,p,s;
	a=sqrt((t.A.x-t.B.x)*(t.A.x-t.B.x)+(t.A.y-t.B.y)*(t.A.y-t.B.y));
	b=sqrt((t.A.x-t.C.x)*(t.A.x-t.C.x)+(t.A.y-t.C.y)*(t.A.y-t.C.y));
	c=sqrt((t.C.x-t.B.x)*(t.C.x-t.B.x)+(t.C.y-t.B.y)*(t.C.y-t.B.y));
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	return s;
}
point G(triangle t){
	point g;
	g.x=(t.A.x+t.B.x+t.C.x)/3;
	g.y=(t.A.y+t.B.y+t.C.y)/3;
	return g;
}
point circumcenter(triangle t){
	double A1,B1,C1,A2,B2,C2;
	point c;
	A1=2*(t.B.x-t.A.x);
	B1=2*(t.B.y-t.A.y);
	C1=t.B.x*t.B.x+t.B.y*t.B.y-t.A.x*t.A.x-t.A.y*t.A.y;
	A2=2*(t.C.x-t.B.x);
	B2=2*(t.C.y-t.B.y);
	C2=t.C.x*t.C.x+t.C.y*t.C.y-t.B.x*t.B.x-t.B.y*t.B.y;
	c.x=((C1*B2)-(C2*B1))/((A1*B2)-(A2*B1));
	c.y=((A1*C2)-(A2*C1))/((A1*B2)-(A2*B1));
	return c;
} 
