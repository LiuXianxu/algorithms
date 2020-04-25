#include <stdio.h>
#include <string.h>
#define N 100001
char hex[N];
char bin[4*N]={'\0'};
int oct[4*N/3];
int top=0;
void htob(char hex[],char bin[]);
void singlechar(char ch,char bin[],int i);
void bto(char bin[],int oct[]);
int tonum(char a,char b ,char c);
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",hex);
		htob(hex,bin);
		bto(bin,oct);
		while(top)
		{
			printf("%d",oct[--top]);
		}
		printf("\n");
	}

	return 0;
}
void htob(char hex[],char b[])
{
	int i=0,j=0;
//	i=strlen(hex)-1;
	while(hex[i])
	{
		singlechar(hex[i],b,4*j);
		j++;
		i++;
	}
}
void singlechar(char ch,char bin[],int i)
{
	switch(ch)
	{
	case '0':bin[i]='0';bin[i+1]='0';bin[i+2]='0';bin[i+3]='0';break;
	case '1':bin[i]='0';bin[i+1]='0';bin[i+2]='0';bin[i+3]='1';break;
	case '2':bin[i]='0';bin[i+1]='0';bin[i+2]='1';bin[i+3]='0';break;
	case '3':bin[i]='0';bin[i+1]='0';bin[i+2]='1';bin[i+3]='1';break;
	case '4':bin[i]='0';bin[i+1]='1';bin[i+2]='0';bin[i+3]='0';break;
	case '5':bin[i]='0';bin[i+1]='1';bin[i+2]='0';bin[i+3]='1';break;
	case '6':bin[i]='0';bin[i+1]='1';bin[i+2]='1';bin[i+3]='0';break;
	case '7':bin[i]='0';bin[i+1]='1';bin[i+2]='1';bin[i+3]='1';break;
	case '8':bin[i]='1';bin[i+1]='0';bin[i+2]='0';bin[i+3]='0';break;
	case '9':bin[i]='1';bin[i+1]='0';bin[i+2]='0';bin[i+3]='1';break;
	case 'A':bin[i]='1';bin[i+1]='0';bin[i+2]='1';bin[i+3]='0';break;
	case 'B':bin[i]='1';bin[i+1]='0';bin[i+2]='1';bin[i+3]='1';break;
	case 'C':bin[i]='1';bin[i+1]='1';bin[i+2]='0';bin[i+3]='0';break;
	case 'D':bin[i]='1';bin[i+1]='1';bin[i+2]='0';bin[i+3]='1';break;
	case 'E':bin[i]='1';bin[i+1]='1';bin[i+2]='1';bin[i+3]='0';break;
	case 'F':bin[i]='1';bin[i+1]='1';bin[i+2]='1';bin[i+3]='1';break;
	}

}
void bto(char bin[],int oct[])
{
	int len,i=0;
	len=strlen(bin);
	i=len-1;
	if(len%3==0)
		while(i>=0)
		{
			if(i==2&&bin[i]=='0'&&bin[i-1]=='0'&&bin[i-2]=='0')break;
			oct[top++]=tonum(bin[i-2],bin[i-1],bin[i]);
			i=i-3;
		}
	else if(len%3==1)
		while(i>=0)
		{
			if(i==0)
			{
				if(bin[i]=='0')break;
				oct[top++]=tonum('0','0',bin[i]);
				i=i-3;
			}
			else
			{
				oct[top++]=tonum(bin[i-2],bin[i-1],bin[i]);
				i=i-3;
			}
		}
	else if(len%3==2)
		while(i>=0)
		{
			if(i==1)
			{
				if(bin[i]=='0'&&bin[i-1]=='0')break;
				oct[top++]=tonum('0',bin[i-1],bin[i]);
				i=i-3;
			}
			else
			{
				oct[top++]=tonum(bin[i-2],bin[i-1],bin[i]);
				i=i-3;
			}
		}


}
int tonum(char a,char b ,char c)
{
	if(a=='0'&&b=='0'&&c=='0')return 0;
	if(a=='0'&&b=='0'&&c=='1')return 1;
	if(a=='0'&&b=='1'&&c=='0')return 2;
	if(a=='0'&&b=='1'&&c=='1')return 3;
	if(a=='1'&&b=='0'&&c=='0')return 4;
	if(a=='1'&&b=='0'&&c=='1')return 5;
	if(a=='1'&&b=='1'&&c=='0')return 6;
	if(a=='1'&&b=='1'&&c=='1')return 7;
}
