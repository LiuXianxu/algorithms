#include <stdio.h>
#include <string.h>
#define N 205
char str[N];
void upcase(char *s);
void lcase(char *s);
void reverse(char *s);
void uplow(char *s);
void suoxie(char *s);
int main(){
	int n;
	scanf("%d %s",&n,str);
	switch(n){
		case 1:upcase(str);break;
		case 2:lcase(str);break;
		case 3:reverse(str);break;
		case 4:uplow(str);break;
		case 5:suoxie(str);break; 
	}
	printf("%s",str);
	return 0;
} 
void upcase(char *s)
{	
	while(*s)
	{
		if(*s>='a'&&*s<='z')
			*s-=32;
		s++;	
	}
}
void lcase(char *s)
{	
	while(*s)
	{
		if(*s>='A'&&*s<='Z')
			*s+=32;
		s++;	
	}
}
void reverse(char *s){
	int i;
	int len =strlen(s);
	for(i=0;i<len/2;i++)
	{
		char temp=s[i];
		s[i]=s[len-i-1];
		s[len-i-1]=temp;
	}
}
void uplow(char *s){
	while(*s)
	{
		if(*s>='A'&&*s<='Z')
			*s+=32;
		else if(*s>='a'&&*s<='z')
			*s-=32;
		s++;	
	}
}
void suoxie(char *s){
	lcase(s);
	int len=strlen(s);
	int i,j,k;
	for(i=0;i<len-1;i++)
	{
		for(j=i;j<len;)
		{
			if(s[j]==s[j+1]-1)
			j++;
			else break;
		}
		if(j-1>i)
		{
			int sublen=j-i;	
			int	t=i+2;
			s[i+1]='-';
			s[i+2]=s[j];
			i=i+3;
			for(k=j+1;s[k]&&k<len;k++)
			{
				s[i]=s[k];
				i++;
			}
			len=len-sublen+2;
			i=t;
		}
	}
	s[len]='\0';
}
