package Exercise4;

import java.util.Scanner;

public class E1 {

	public static int[] f(int[] x,int n,int len)
	{
		int[] newX =new int[50] ;
		int index = 0 ;
		n %= 50;
		for(int i=n-1;i>=0;i--)
		{
			newX[index++]=x[i];
		}
		for(int i=len-1;i>=n;i--)
		{
			newX[index++]=x[i];
		}
		return newX;
	}
	public static void main(String[] args) {
		
		int [] x = new int[50] ;
		int top = 0;
		Scanner in = new Scanner(System.in);
		while(in.hasNextInt()&&top<50)
		{
			x[top] = in.nextInt();
			top++;
		}
		in.next();
		int n=in.nextInt();
		x=f(x,n,top);
		for(int i=0;i<top;i++)
		{
			System.out.print(x[i]+" ");
		}
	}
	
}
