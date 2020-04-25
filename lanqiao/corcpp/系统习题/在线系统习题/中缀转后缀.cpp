#include <stdio.h>
char str[105]={'\0'};
char pf[105]={'\0'};
char stack[100];
int top=0;
int prority(char op){
	switch(op){
	case '(' :return 0;//±ÜÃâ'('½øÕ» 
	case '+' :
	case '-' :return 1;
	case '*' :
	case '/' :return 2;
	default:return 0;
	}
}
int is_op(char op){
	switch(op){
		case '+':
		case '-':
		case '*':
		case '/':return 1;
		default: return 0;
	}
}
void ToPos(char str[],char pf[]){
	int i=0,j=0,t=0;
	for(i=0;str[i];i++)
	{	
		if(str[i]>='0'&&str[i]<='9')
			pf[j++]=str[i];
		else if(str[i]=='(')
			stack[top++]=str[i];
		else if(str[i]==')')
		{
			t=top-1;
			while(stack[t]!='(')
			{
				pf[j++]=stack[--top];
				t=top-1;
			}
			top--;
			
		}
		else if (is_op(str[i])){
			pf[j++]=' ';
			while(prority(stack[top-1])>=prority(str[i]))
				pf[j++]=stack[--top];
			stack[top++]=str[i];
		}
	}
	while(top)
		pf[j++]=stack[--top];
}
int readnumber(char pf[],int *i){
	int x=0;
	while(pf[*i]>='0'&&pf[*i]<='9'){
		x=x*10+(pf[*i]-'0');
		(*i)++;
	}
	return x;	
}
int evalpost(char pf[]){
	int obst[100];
	int top=0,i=0,x1,x2;
	while(pf[i]){
		if(pf[i]>='0'&&pf[i]<='9')
			obst[top++]=readnumber(pf,&i);
		else if(pf[i]==' ')	i++;
		else if(pf[i]=='+'){
			x2=obst[--top];
			x1=obst[--top];
			obst[top++]=x1+x2;
			i++;
		}
			else if(pf[i]=='-'){
			x2=obst[--top];
			x1=obst[--top];
			obst[top++]=x1-x2;
			i++;
		}
			else if(pf[i]=='*'){
			x2=obst[--top];
			x1=obst[--top];
			obst[top++]=x1*x2;
			i++;
		}
			else if(pf[i]=='/'){
			x2=obst[--top];
			x1=obst[--top];
			obst[top++]=x1/x2; 
			i++;
		}
	}
	return obst[0];
}
int main(){
	scanf("%s",str);
	ToPos(str,pf);
	printf("%d",evalpost(pf));
	return 0;
} 
