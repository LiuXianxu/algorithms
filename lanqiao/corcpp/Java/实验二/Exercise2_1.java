package Text2;

import java.util.Scanner;

public class Exercise2_1 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("�����������Ʒ�ɱ�:");
		double cost = in.nextDouble();
		if(cost >=210)
		{
			System.out.println("��Ӯ��"+cost*0.14+"��Ԫ���ۿۡ����㹺���14%��");
		}
		else if(cost >=150)
		{
			System.out.println("��Ӯ��"+cost*0.12+"��Ԫ���ۿۡ����㹺���12%��");
		}
		else if(cost>=60)
		{
			System.out.println("��Ӯ��"+cost*0.1+"��Ԫ���ۿۡ����㹺���10%��");
		}
		else if(cost>=10)
		{
			System.out.println("��Ӯ��"+cost*0.08+"��Ԫ���ۿۡ����㹺���8%��");
		}
		else 
		{
			System.out.println("No coupon!");
		}
	}

}
