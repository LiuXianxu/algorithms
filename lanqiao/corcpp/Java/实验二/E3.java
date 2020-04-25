package Exercise4;
import java.util.*;
public class E3 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Integer> arry=new ArrayList<Integer>();
		System.out.println("亲输入数组的元素");
		Scanner in=new Scanner(System.in);
		while(in.hasNextInt()){
			Integer num=in.nextInt();
			arry.add(num);
		}
		sort(arry);
		System.out.println("排序后为:");
		for(int i=0;i<arry.size();i++) {
			System.out.println(arry.get(i));
		}
	}
 public static void sort(ArrayList<Integer> arry) {
	for(int i=0;i<arry.size()-1;i++)
		for(int j=i+1;j<arry.size();j++) {
			if(arry.get(i)>arry.get(j)) {
			Integer t=arry.get(i);
			arry.set(i, arry.get(j));
			arry.set(j,t);
		};
}
}
}