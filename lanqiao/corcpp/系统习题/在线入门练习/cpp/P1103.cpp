#include<stdio.h>
typedef struct 
{
	float a;
	float b;
}complex;
complex add(complex x,complex y);
complex sub(complex x,complex y);
complex mul(complex x,complex y);
complex div(complex x,complex y);
int main()
{
	complex x,y,z;
	char c;
	scanf("%c ",&c);
	scanf("%f%f%f%f",&x.a,&x.b,&y.a,&y.b);
	switch(c)
	{
	case '+':z=add(x,y);break;
	case '-':z=sub(x,y);break;
	case '*':z=mul(x,y);break;
	case '/':z=div(x,y);break;
	}
	printf("%.2f+%.2fi",z.a,z.b);
	return 0;
}
complex add(complex x,complex y)
{
	complex c;
	c.a=x.a+y.a;
	c.b=x.b+y.b;
	return c;
}
complex sub(complex x,complex y)
{
	complex c;
	c.a=x.a-y.a;
	c.b=x.b-y.b;
	return c;
}
complex mul(complex x,complex y)
{
	complex c;
	c.a=x.a*y.a-x.b*y.b;
	c.b=x.a*y.b+x.b*y.a;
	return c;
}
complex div(complex x,complex y)
{
	complex c;
	c.a=(x.a*y.a+x.b*y.b)/(y.a*y.a+y.b*y.b);
	c.b=(x.b*y.a-x.a*y.b)/(y.a*y.a+y.b*y.b);
	return c;
}