/*
	Name: ���ű�����������ȫ���У� 
	Copyright: ���㷨��KeepThinking_�ṩ 
	Author: Jopus
	Date: 08/02/14 19:57
	Description: dev-cpp 5.5.3
*/
#include <stdio.h>
/*˼·����list[1,2,3,4,5,6,7,8,9]�������ȫ���У�Ȼ�����ÿһ�����н��д���
����������list���黮��Ϊ������a,b,c���ж��Ƿ�����number == a+b/c && b%c == 0; 
���������......... 
*/
int x = 0, number = 0, count = 0;

//����a,b���� 
void Swap(int &a,int &b)  
{
	int temp=a;
	a=b;
	b=temp;
}
//����������ת��Ϊ���� 
int getNum(int list[], int f, int r)  
{  
    int i = 0, num = 0;  
    for (i = f; i <= r; i++)   
        num = list[i] + num * 10; //��λ 
    return num;  
}  
//����ȫ���в���ÿ�����н�����д��� 
void Prim(int list[], int k, int m)
{
	if(k==m-1) //ǰ׺�����һ��λ��,��ʱ����һ��������.
	{
		int a = 0, b = 0, c = 0, bLast = 0;   //��������a+b/c 
		for (int i = 0; i < x; i++)           //i��ʾa��ĩβλ�ã����ᳬ��numberλ��  
        {  
            a = getNum(list, 0, i);           //��list�����е�[0-i]ת��Ϊ���֣���ֵ��a 
            bLast=((number-a)*list[8])%10;    //ȷ��b���һ������   
            for (int j =i+(8-i)/2; j < 8; j++)//��list�����м�λ�ÿ�ʼ��bĩβλ�� 
            {                               
                if(list[j]==bLast)            //�ҵ�bβ�� 
                {  
                    b = getNum(list, i+1, j); //��list�����е�[i+1-j]ת��Ϊ���֣���ֵ��b
                    c = getNum(list, j+1, 8); //��list�����е�[j+1-8]ת��Ϊ���֣���ֵ��c 
                    if (b % c == 0 && a + b / c == number)  //�жϺ����� 
					{   
						//printf("%d+%d/%d\n",a,b,c);     //��ӡÿ����� 
                        ++count; 
					} 
                    break;  
                }  
            }      
        }  		 
	}
	else
	{
		for(int i=k;i<m;i++)      //ȫ��������list[] 
		{
			//����ǰ׺,ʹ֮������һ��ǰ׺.
		if(i!=k)	Swap(list[k],list[i]);                //>>A
			Prim(list,k+1,m);                     //>>B
			//��ǰ׺������,��������һ����ǰ׺����.//>>C
		if(i!=k)	Swap(list[k],list[i]);
		}
	}
}
//������ 
int main()
{
	int temp = 0;
	int list[] = {1,2,3,4,5,6,7,8,9};  //����ȫ�������� 
	scanf("%d",&number);               
	temp = number;
	while (temp != 0)      //ͳ��number�ܹ�����λ 
    {  
        ++x;  
        temp /= 10;  
    }  
    Prim(list,0,9);    
    printf("%d", count);   //��ӡ�ܹ������� 
	return 0;
}
