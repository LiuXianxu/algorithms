package Text2;

import java.util.Scanner;

public class Exercise1 {
	public static void main(String[] args) {
		Scanner in =new Scanner(System.in);
		System.out.print("������һ������1,000��999,999֮���������");
		String str = in.next();
		System.out.println(str.replaceAll(",", ""));
	}

}
