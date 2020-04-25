#include <stdio.h>
int main(){
	int v1,v2,t,s,len;
	int s1,s2=0,i,j,count=0;
	scanf("%d%d%d%d%d",&v1,&v2,&t,&s,&len);
	for(i=1;;i++){
		
		s1=v1*i;
		s2=s2+v2;
		if(s1<len&&s2<len&&s1-s2>=t)
		{
			j=0;
			while(++j<=s)
			{
				if(len==s2)break;
				s2=s2+v2;
				count++;
			}
		}
		if(s1==len&&s2==len)
		{
			printf("D\n");
			printf("%d",i+count);
			break;
		}
		else if(s2==len){	
			printf("T\n");
			printf("%d",i+count);
			break;
		}
		else if(s1==len)
		{
			printf("R\n");
			printf("%d",i+count);
			break;
		}
		
	}
	return 0;
} 
