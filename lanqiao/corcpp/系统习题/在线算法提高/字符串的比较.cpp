#include<stdio.h>
#include <string.h>
int equal(char a[],char b[]); 
int main(){
	char a[12],b[12];
	scanf("%s%s",a,b);
	if(strlen(a)!=strlen(b))
	printf("1");
	else if(strcmp(a,b)==0)
	printf("2");
	else if(equal(a,b))
	printf("3");
	else printf("4");
	
	return 0;
}
int equal(char a[],char b[]){
	int i=0,count=0;
	while(a[i]==b[i]&&a[i]!='\0'||a[i]-b[i]==32||b[i]-a[i]==32)
	{
		count++;
		i++;
	}
	if(count==strlen(a))
	return 1;
	else return 0;
	
}
