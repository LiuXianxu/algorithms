#include <stdio.h>
int prime(int n);
int main(){
	int i[6],sum=0,L,R,count=0;
	scanf("%d%d",&L,&R);
	for(i[0]=0;i[0]<3;i[0]++)
		for(i[1]=0;i[1]<3;i[1]++) 
			for(i[2]=0;i[2]<3;i[2]++) 
				for(i[3]=0;i[3]<3;i[3]++) 
					for(i[4]=0;i[4]<3;i[4]++)
						for(i[5]=0;i[5]<3;i[5]++)
						{
							sum=i[0]+i[1]+i[2]+i[3]+i[4]+i[5];
							if(prime(sum)||sum>=L&&sum<=R)
							count++;
						}
	printf("%d",count);
	return 0;
}
int prime(int n){
	int i;
	if(n<2)return 0;
	else
	{
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
			return 0;
		}
		return 1;
	}
} 
