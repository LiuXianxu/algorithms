#include <stdio.h>
int main(){
	int index[100],queue[100];
	int front=0,rear=0,n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&index[i]);
		if(index[i]==1)
		scanf("%d",&queue[rear++]);
		if(index[i]==2&&front<rear)
			printf("%d\n",queue[front++]);
		else	if(index[i]==2&&front>=rear)
		{
			printf("no\n");
			break;
		}
		if(index[i]==3&&front<=rear) printf("%d\n",rear-front);
		else if(index[i]==3&&front>rear)
		{
			printf("no\n");
			break;
		}
	}
/*	for(i=0;i<n;i++)
	{
		if(index[i]==2&&front<rear)
			printf("%d\n",queue[front++]);
		else	if(index[i]==2&&front>=rear)
		{
			printf("no\n");
			break;
		}
		if(index[i]==3&&front<=rear) printf("%d\n",rear-front);
		else if(index[i]==3&&front>rear)
		{
			printf("no\n");
			break;
		}
			
	}	
*/
	return 0;
}
