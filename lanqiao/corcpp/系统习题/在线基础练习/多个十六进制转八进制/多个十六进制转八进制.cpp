#include <stdio.h>
#define N 100001
char str[10][N];
char bin[10][4*N];
int oct[10][N];
void hexbin(char hex,char **bin,int i,int j){
	switch(hex){
		case '0':bin[i][j]='0';bin[i][j+1]='0';bin[i][j+2]='0';bin[i][j+3]='0';break;
	}
}
void binoct(char **bin,int i,int j,int **oct){
}
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",str[i]);
	}
	return 0;
} 
