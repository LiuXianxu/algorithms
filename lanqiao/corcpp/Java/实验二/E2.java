package Exercise4;

import java.util.ArrayList;
//import java.util.Iterator;
import java.util.Scanner;

public class E2 {
	public static void main(String[] args) {
		ArrayList<Integer> arrayList = new ArrayList<Integer>();
		Scanner in = new Scanner(System.in);
		while(in.hasNextInt())
		{
			arrayList.add(in.nextInt());
		}
		in.close();
		for(int i=0;i<arrayList.size()-1;i++)
		{
			int k = i;
			for(int j=i+1;j<arrayList.size();j++)
			{
				if(arrayList.get(j)<arrayList.get(k))
				{
					k=j;
				}
			}
			Integer temp = new Integer(arrayList.get(i));
			arrayList.set(i, arrayList.get(k));
			arrayList.set(k, temp);
	
		}
		for(Integer element: arrayList)
		{
			System.out.print(element+" ");
		}
//		System.out.println();
//		
//		Iterator it = arrayList.iterator();
//		while(it.hasNext())
//		{
//			System.out.print(it.next()+" ");
//		}
	}
}
