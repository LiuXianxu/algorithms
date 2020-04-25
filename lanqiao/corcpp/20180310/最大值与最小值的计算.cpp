#include <stdio.h>
#define INF 0x3f3f3f3f 
int main()
{
	int cnt=0,temp;
	int max=-INF,min=INF;
	while(cnt<=10)
	{
		cnt += scanf("%d",&temp);
		if(temp>=max)
		{
			max = temp;
		}
		if(temp<=min)
		{
			min = temp;
		}
	}
	printf("%d %d",max,min);
	return 0;
} 
