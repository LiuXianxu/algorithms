#include <stdio.h>
#include <string.h>
void TransInformation(int a);
int main()
{
	int data[15][40];
	int n=10,m=32;
	freopen("C:\\Users\\ÎÒµÄµçÄÔ\\Desktop\\in.txt","r",stdin); 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&data[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			TransInformation(data[i][j]);
			if(j&1)
			{
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}
void TransInformation(int a)
{
	bool is =true ;
	if(a<0)
	{
		is = false ;
		a = -a;
	}
	int binary[8]={0};
	memset(binary,0,sizeof(binary));
	int index = 0;
	while(a>1)
	{
		binary[index]= a%2;
		a /=2;
		index++;
	}
	binary[index]=a;
	if(!is)
	{
		for(int i=0;i<8;i++)
		{
			binary[i] ^= 1;
		}
		
		for(int i=0;i<8;i++)
		{
			int temp;
			if(i==0)
			{
				temp = binary[i] += 1;
			}
			else
			{
				temp = binary[i];
			}
			if(temp>=2)
			{
				binary[i+1] +=1;
				binary[i] %=2;
			} 
			else
			{
				break;
			}
		}
	}
	for(int i=7;i>=0;i--)
	{
		if(binary[i]==1)
		{
			printf("#");
		}
		else
		{
			printf(" ");
		}
	}
}
