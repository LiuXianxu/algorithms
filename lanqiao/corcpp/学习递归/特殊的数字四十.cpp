#include <stdio.h>
int main()
{
	int i[4];
	for(i[0]=1;i[0]<10;i[0]++)
		for(i[1]=0;i[1]<10;i[1]++)
			for(i[2]=0;i[2]<10;i[2]++)
				for(i[3]=0;i[3]<10;i[3]++)
					if(i[0]+i[1]+i[2]+i[3]==10)
						printf("%d%d%d%d\n",i[0],i[1],i[2],i[3]);	
	return 0; 
}
