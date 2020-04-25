#include <stdio.h>
//#include <iostream>
//using namespace std;
/*
递归(分治法思想):
设(ri)perm(X)表示每一个全排列前加上前缀ri得到的排列.
当n=1时,perm(R)=(r) 其中r是唯一的元素,这个就是出口条件.
当n>1时,perm(R)由(r1)perm(R1),(r2)perm(R2),...(rn)perm(Rn)构成.
*/
//此处为引用,交换函数.函数调用多,故定义为内联函数.
inline void Swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void Perm(int list[],int k,int m); 
void Perm(int list[],int k,int m) //k表示前缀的位置,m是要排列的数目.
{
	if(k==m-1) //前缀是最后一个位置,此时打印排列数.
	{
		for(int i=0;i<m;i++)
			printf("%d",list[i]);
		printf("\n");
	}
	else
	{
		for(int i=k;i<m;i++)
		{
			//交换前缀,使之产生下一个前缀.
		if(i!=k)
		{
			Swap(list[k],list[i]);
		//	printf("list[k=%d]=%d,list[i=%d]=%d\n",k,list[k],i,list[i]);
		}
			Perm(list,k+1,m);
			if(i!=k)	Swap(list[k],list[i]);
		}
	}
}

int main()
{
	int list[] = {1,2,3,4,5,6,7,8,9};
	Perm(list,0,4);
	return 0;
}

