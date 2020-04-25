#include <stdio.h>
int main()
{
	int p[100];
	int num,cnt=0;
	int s,i;
	for(num=2;num<10000;num++)
	{
		cnt=0;
		s=num;
		for(i=1;i<num/2+1;i++)
		{
			if(num % i ==0)
			{
				p[cnt++]=i;
				s-=i;
			}
		}
		if(s==0)
		{
			printf("%d\n",num);
		/*	printf("%d=",num);
			while(cnt>1)
			{
				printf("%d+",p[--cnt]);
			}
			printf("%d\n",p[--cnt]);		
			cnt=0;
		*/
		}
	}
	
	return 0;
} 
