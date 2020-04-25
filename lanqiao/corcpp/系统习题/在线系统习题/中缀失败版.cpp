#include <stdio.h>
int stack[100]={0};
char opstack[100]={'\0'};
int top=0,opt=0;
char str[105]={'\0'};
void readstr(char str[])
{
	int i,flag=0;
	for(i=0;str[i];i++)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='('||str[i]==')')
		{
			opstack[opt++]=str[i];
			flag=0;
		}
		else
		{
			if(!flag)
			{	
				stack[top++]=str[i]-'0';
				flag=1;
			}	
			else
				stack[top-1]=stack[top-1]*10+(str[i]-'0');
		}
	}
}
int prority(char op)
{
	switch(op)
	{
	case '\0':return -1;
	case '(':return 0;
	case '+':
	case '-':return 1;
	case '*':return 2;
	case '/':return 3;
	}
	return 0;
}
void putstack()
{
	char op;
	if(!prority(opstack[--opt]))
		op=opstack[--opt];
	else
		op=opstack[opt];
}
int main()
{
	int i;
	scanf("%s",str);
	readstr(str);
	printf("%s",opstack);
	for(i=0;i<top;i++)
	{
		printf(" %d ",stack[i]);
	}
	return 0;
}