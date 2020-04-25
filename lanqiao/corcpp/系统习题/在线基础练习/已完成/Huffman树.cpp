#include <stdio.h>
#define N 100
int stack[N];
void sort(int a[],int n);
int main(){
	int n,i,top,sum=0,x1,x2;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&stack[i]);
	}
	sort(stack,n);
	top=n;
	while(top!=1)
	{
		x1=stack[--top];
		x2=stack[--top];
		sum=sum+x1+x2;
		stack[top++]=x1+x2;
		sort(stack,top);
	}
	if(n>1)
	printf("%d",sum);
	else
	printf("%d",stack[--top]);
	return 0;
}
void sort(int a[],int n){
	int i,j,k,t;
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++)
			if(a[k]<a[j])
			k=j;
		t=a[i];
		a[i]=a[k];
		a[k]=t;
	}
}
