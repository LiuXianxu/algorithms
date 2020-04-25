#include <stdio.h>
#define N 100
char A[N]={'\0'};
char B[N]={'\0'};
int a[N]={0};
int b[N]={0};
int c[N+1]={0};
int toint(char A[],int a[]);
void reverse(int a[],int len);
int add(int a[],int b[],int c[],int len);
void print(int c[],int len);
int main(){
	int i,alen,blen,clen;
	scanf("%s",A);
	scanf("%s",B);
	alen=toint(A,a);
	blen=toint(B,b);
	reverse(a,alen);
	reverse(b,blen);
	if(alen>blen)
	{
		clen=add(a,b,c,alen);
		print(c,clen);
	}
	else{
		clen=add(a,b,c,blen);
		print(c,clen);
		}
	return 0;
} 
int toint(char A[],int a[])
{
	int i=0;
	while(A[i])
	{
		a[i]=A[i]-'0';
		i++;
	}
	return i;
}
void reverse(int a[],int len){
	int i,t;
	for(i=0;i<len/2;i++)
	{
		t=a[i];
		a[i]=a[len-i-1];
		a[len-i-1]=t;
	}
/*	printf("×ªÖÃºóÊä³ö£º");
	for(i=0;i<len;i++)
		printf("%d",a[i]);
	printf("\n");
	*/
}
int add(int a[],int b[],int c[],int len)
{
	int i,d=0,t;
	int clen;
	for(i=0;i<len;i++)
	{
		t=a[i]+b[i]+d;
		d=t/10;
		c[i]=t%10;
	}
	if(d){
		c[i]=d;
		clen=i+1;
	}
	else
	clen=i;
	reverse(c,clen);
	return clen;
}
void print(int c[],int len){
	int i;
	for(i=0;i<len;i++)
	printf("%d",c[i]);
}
