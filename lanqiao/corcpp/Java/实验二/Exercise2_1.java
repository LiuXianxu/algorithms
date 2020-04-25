package Text2;

import java.util.Scanner;

public class Exercise2_1 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("请输入你的商品成本:");
		double cost = in.nextDouble();
		if(cost >=210)
		{
			System.out.println("你赢了"+cost*0.14+"美元的折扣。（你购买的14%）");
		}
		else if(cost >=150)
		{
			System.out.println("你赢了"+cost*0.12+"美元的折扣。（你购买的12%）");
		}
		else if(cost>=60)
		{
			System.out.println("你赢了"+cost*0.1+"美元的折扣。（你购买的10%）");
		}
		else if(cost>=10)
		{
			System.out.println("你赢了"+cost*0.08+"美元的折扣。（你购买的8%）");
		}
		else 
		{
			System.out.println("No coupon!");
		}
	}

}
