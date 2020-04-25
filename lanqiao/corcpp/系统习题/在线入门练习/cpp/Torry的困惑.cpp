#include <stdio.h>
#include <math.h>
//int sum[100005];
int zhishu(int n)
{
	//printf("%d ",n);
	int i;
	if(n<2)return 0;
	else{
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
				return 0;
		}
		return 1;
	}
}
int main()
{
	int sum=1;
	int i,n,count=0;
	scanf("%d",&n);
	//printf("-----%d----\n",zhishu(2));
	for(i=2;i<10000000000;i++)
	{
		if(zhishu(i)&&++count)
		{
		//	printf("%d----\n",i);
			sum=sum*i;
			sum=sum%50000;
			if(count>=n)break;
		}
	}
	printf("%d",sum);
	return 0;
}
