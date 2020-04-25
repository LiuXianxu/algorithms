#include <stdio.h>
void fj(int n){
	if(n==0)printf("%c",'A');
	else
	{
		fj(n-1); 			
		printf("%c",n+'A');  
		fj(n-1);
	}
} 
int main(){
	int n;
	scanf("%d",&n);
	fj(n-1);
	return 0;
}
