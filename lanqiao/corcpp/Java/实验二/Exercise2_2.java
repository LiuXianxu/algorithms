package Text2;

import java.util.Scanner;

public class Exercise2_2 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("�����������Ʒ�ɱ�:");
		int cost = in.nextInt();
		switch(cost/10)
		{
		case 0:System.out.println("No coupon!");break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:System.out.println("��Ӯ��"+cost*0.08+"��Ԫ���ۿۡ����㹺���8%��");break;
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:System.out.println("��Ӯ��"+cost*0.1+"��Ԫ���ۿۡ����㹺���10%��");break;
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:System.out.println("��Ӯ��"+cost*0.12+"��Ԫ���ۿۡ����㹺���12%��");break;
		default :System.out.println("��Ӯ��"+cost*0.14+"��Ԫ���ۿۡ����㹺���14%��");break;
		}
	}
}
