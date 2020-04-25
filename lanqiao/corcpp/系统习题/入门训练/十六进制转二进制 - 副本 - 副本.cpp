#include <stdio.h>
#include <string.h>
#define N 100001 
typedef char string[N];
typedef char binary[N];
typedef int octal[N];
string str[10];
binary bin[10];
octal oct[10];
int olen=0;
void ToBin(char a[],char c,int i){
	switch(c){
		case '0':a[4*i]='0';a[4*i+1]='0';a[4*i+2]='0';a[4*i+3]='0';break; //0000
		case '1':a[4*i]='0';a[4*i+1]='0';a[4*i+2]='0';a[4*i+3]='1';break; //0001
		case '2':a[4*i]='0';a[4*i+1]='0';a[4*i+2]='1';a[4*i+3]='0';break; //0010
		case '3':a[4*i]='0';a[4*i+1]='0';a[4*i+2]='1';a[4*i+3]='1';break; //0011
		case '4':a[4*i]='0';a[4*i+1]='1';a[4*i+2]='0';a[4*i+3]='0';break; //0100
		case '5':a[4*i]='0';a[4*i+1]='1';a[4*i+2]='0';a[4*i+3]='1';break; //0101
		case '6':a[4*i]='0';a[4*i+1]='1';a[4*i+2]='1';a[4*i+3]='0';break; //0110
		case '7':a[4*i]='0';a[4*i+1]='1';a[4*i+2]='1';a[4*i+3]='1';break; //0111
		case '8':a[4*i]='1';a[4*i+1]='0';a[4*i+2]='0';a[4*i+3]='0';break; //1000
		case '9':a[4*i]='1';a[4*i+1]='0';a[4*i+2]='0';a[4*i+3]='1';break; //1001
		case 'A':a[4*i]='1';a[4*i+1]='0';a[4*i+2]='1';a[4*i+3]='0';break; //1010
		case 'B':a[4*i]='1';a[4*i+1]='0';a[4*i+2]='1';a[4*i+3]='1';break; //1011
		case 'C':a[4*i]='1';a[4*i+1]='1';a[4*i+2]='0';a[4*i+3]='0';break; //1100
		case 'D':a[4*i]='1';a[4*i+1]='1';a[4*i+2]='0';a[4*i+3]='1';break; //1101
		case 'E':a[4*i]='1';a[4*i+1]='1';a[4*i+2]='1';a[4*i+3]='0';break; //1110
		case 'F':a[4*i]='1';a[4*i+1]='1';a[4*i+2]='1';a[4*i+3]='1';break; //1111
	}
}
int ToOct(char a,char b,char c){
	if(a=='0'&&b=='0'&&c=='0')return 0;
	if(a=='0'&&b=='0'&&c=='1')return 1;
	if(a=='0'&&b=='1'&&c=='0')return 2;
	if(a=='0'&&b=='1'&&c=='1')return 3;
	if(a=='1'&&b=='0'&&c=='0')return 4;
	if(a=='1'&&b=='0'&&c=='1')return 5;
	if(a=='1'&&b=='1'&&c=='0')return 6;
	if(a=='1'&&b=='1'&&c=='1')return 7;
	return 0;
}
void HtoB(char str[]){
	int i;
	for(i=0;str[i];i++)
	{
		ToBin(bin,str,i);
	}
} 
void BtoO(char bin[]){
	int i,flag=0;
	for(i=0;bin[i];)
	{
		if(bin[i]!='0')flag=1;
	
		if(flag)
		{
			if(!bin[i+1])
			oct[olen++]=ToOct(bin[i],'0','0');
			else if(!bin[i+2])
			oct[olen++]=ToOct(bin[i],bin[i+1],'0');
			else 
			oct[olen++]=ToOct(bin[i],bin[i+1],bin[i+2]);
			i=i+3;
		}
		else i++;
	}
}
void printBin(char bin[]){
	int	flag=0,i;
	for(i=0;bin[i];i++)
	{
		if(bin[i]!='0')flag=1;
		if(flag)printf("%c",bin[i]);
	}
	printf("\n");
}
void printOct(int oct[]){
	int i;
	for(i=0;i<olen;i++)	
	printf("%d",oct[i]);
	printf("\n");
	olen=0;
}
int main(){
	int i,n=1;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
	scanf("%s",str[i]);
	HtoB(str[i]);
	BtoO(bin[i]);
	printOct(oct[i]);
	}
	
	return 0;
} 
/*	memset(bin,'\0',sizeof(char)*N*4);
	或者：memset(bin,'\0',sizeof(bin));
	memset(oct,'\0',sizeof(int)*N*2);
	或者：memset(oct,'\0',sizeof(oct));
*/
