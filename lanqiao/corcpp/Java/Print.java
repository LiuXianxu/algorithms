package Text2;

public class Print
{
	public static void f(int n,int max)
	{
		if(n==max)
		{
			return ;
		}
		else
		{
			for(int i=0;i<=n;i++)
			{
				System.out.print("[]"+" ");
			}
			System.out.println();
			f(n+1,max);
			
		}
	}
	public static void main(String[] args)
	{
		f(0,5);
	}
}
