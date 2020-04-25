#include <stdio.h>
char str[25];
int main(){
	int i=0;
	scanf("%s",str);
	while(str[i]){
		if(str[i]>='a'&&str[i]<='z')
			str[i]=str[i]-32;
		else if(str[i]>='A'&&str[i]<='Z')
			str[i]=str[i]+32;
		i++; 
	}
	printf("%s",str);
	
	return 0;
}
