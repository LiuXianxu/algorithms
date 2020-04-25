#include <stdio.h>
char a[8]={'\0'};
char b[8]={'\0'};
char c[16]={'\0'};
int top=0;
int ToNum(char ch)
{
	return ch-'0';
}
int getlen(char t[])
{
	int i=-1;
	while(t[++i]);
	printf("%d\n",i);
	return i;
}
void reverse(char t[]){
	int len = getlen(t),i;
	char ch;
	for(i=0;i<len/2;i++)
	{
		ch =t[i];
		t[i]=t[len-i-1];
		t[len-i-1]=ch;
	}
}
void multiply(char a[],char b[],char c[]){
	int n,t,i,j,k=0,c=0;
	int temp[16];
	reverse(a);
	reverse(b);
	for(i=0;a[i];i++)
	{
		for(j=0;b[j];j++)
		{
			c=0;
			if(i+j<=k){
				if(i>j)break;
			t=ToNum(a[i])*ToNum(a[i]);
			if(t>9){
			c=c+t%10;
			temp[j+k]=t%10;
			}
			else
			temp[j+k]=t;
		}
		k++;
		
	}
}
int main(){

	scanf("%s",a);
	printf("%s",a);
	return 0;
} 
/*	int c=0,i,t;
	for(i=7;i>=0;i--)
	{
		t=ToNum(a[i])*ToNum(b[i]);
		c=t%10;
		c[top++]=c;
	}
	*/
