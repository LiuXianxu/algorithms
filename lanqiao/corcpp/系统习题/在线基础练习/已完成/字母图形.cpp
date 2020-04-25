#include <stdio.h>
int main(){
	int i,j,n,m,ch,flag=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		ch='A'+i;
		if(ch>90)ch=ch-26;
		printf("%c",ch);
			if(ch>65) flag=1;
		for(j=1;j<m;j++)
		{
			
			if(flag)
			{
			printf("%c",--ch);
			if(ch==65)flag=0;
			}
			else
			{
			printf("%c",++ch);
			}
			
		}
		printf("\n");
	}
	
	return 0;
}
