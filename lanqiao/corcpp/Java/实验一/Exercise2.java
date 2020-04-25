package Text1;

import java.util.Scanner;

public class Exercise2 {
	public static void main(String[] args) {
	
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		do 
		{
			System.out.print(a%10);
			a /= 10;
		} while(a>0);
		
	}
}
