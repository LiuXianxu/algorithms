#include <stdio.h>
#define N 8005
int main()
{
	int i,j,k,n;
	char s[N];
	scanf("%d",&n);
	scanf("%s",s);
	int end=n-1;
	int cnt =0;
	int PrimeNum=0;
	for(i=0;i<end;i++)
	{
		for(j=end;j>=i;j--)
		{
			if(j==i)
			{
				if(n%2==0||PrimeNum)
				{
					printf("Impossible");
					return 0;
				}
				PrimeNum++;
				cnt += n/2 -i;
			}
			else if(s[i]==s[j])
			{
				for(k=j;k<end;k++)
				{
					char temp=s[k];
					s[k]=s[k+1];
					s[k+1]=temp;
					cnt++;
				}
				end--;
				break;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
