#include <stdio.h>
char str[5][105];
int main()
{
	int i,j;
	int num[5]={0};
	for(i=0;i<5;i++)
		scanf("%s",str[i]);
	for(i=0;i<5;i++)
		for(j=0;j<105&&str[i][j];j++)
			num[i]++;
	int max=0;
	for(i=1;i<5;i++)
		if(num[max]<num[i])
		max=i;
	printf("%s",str[max]);
	return 0;
}