#include <stdio.h>
//#include <iostream>
//using namespace std;
/*
�ݹ�(���η�˼��):
��(ri)perm(X)��ʾÿһ��ȫ����ǰ����ǰ׺ri�õ�������.
��n=1ʱ,perm(R)=(r) ����r��Ψһ��Ԫ��,������ǳ�������.
��n>1ʱ,perm(R)��(r1)perm(R1),(r2)perm(R2),...(rn)perm(Rn)����.
*/
//�˴�Ϊ����,��������.�������ö�,�ʶ���Ϊ��������.
inline void Swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void Perm(int list[],int k,int m); 
void Perm(int list[],int k,int m) //k��ʾǰ׺��λ��,m��Ҫ���е���Ŀ.
{
	if(k==m-1) //ǰ׺�����һ��λ��,��ʱ��ӡ������.
	{
		for(int i=0;i<m;i++)
			printf("%d",list[i]);
		printf("\n");
	}
	else
	{
		for(int i=k;i<m;i++)
		{
			//����ǰ׺,ʹ֮������һ��ǰ׺.
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

