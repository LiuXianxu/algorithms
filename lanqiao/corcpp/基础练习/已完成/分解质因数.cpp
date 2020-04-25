#include <stdio.h>
int prime(int n);
void factorization(int num);
int main(){
	int i,a,b;
	scanf("%d%d",&a,&b);
	for(i=a;i<=b;i++)
	if(prime(i)) printf("%d=%d\n",i,i);
	else 
	factorization(i);
	return 0;
} 
int prime(int n){
	int i;
	if(n<2)return 0;
	else 
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)return 0;	
	}
	return 1;
}
void factorization(int num){
	int i;
	printf("%d=",num);
	for(i=2;i<=num;i++)
	{
		while(num%i==0)
		{
			num/=i;
			num==1?printf("%d",i):printf("%d*",i);
		}
	} 
	printf("\n");
}
