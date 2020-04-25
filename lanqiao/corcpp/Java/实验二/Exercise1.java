package Text2;

import java.util.Scanner;

public class Exercise1 {
	public static void main(String[] args) {
		Scanner in =new Scanner(System.in);
		System.out.print("请输入一个介于1,000和999,999之间的整数：");
		String str = in.next();
		System.out.println(str.replaceAll(",", ""));
	}

}
