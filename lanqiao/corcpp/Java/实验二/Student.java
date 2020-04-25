package Text3;

public class Student {

	
	private int num;
	private String name;
	private int age;
	private String address;
	Student(int num,String name,int age,String address)
	{
		this.num =num;
		this.name = name;
		this.age = age;
		this.address= address;
	}
	public int getNum() {
		return num;
	}
	public void setNum(int num) {
		this.num = num;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getAddress() {
		return address;
	}
	public void setAddress(String address) {
		this.address = address;
	}
	public boolean ageIsEqual(int age)
	{
		if(this.age==age)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	public boolean addressIsEqual(String address)
	{
		
		return 	this.address.equals(address);
	}
	public static void main(String[] args) {
		Student s1 = new Student(1,"张三",18,"江西省南昌市");
		Student s2 = new Student(2,"李四",18,"江西省南昌市");
		System.out.println(s1.ageIsEqual(s2.getAge()));
		System.out.println(s1.addressIsEqual(s2.getAddress()));
	}
}
