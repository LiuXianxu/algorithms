#include <iostream>
#include <stdlib.h>
#define MAXLENGTH 100
using namespace std;
class String{
	public:
		void display();
		void input(String &s); 
		void output(String &s);
		/*char getstr(int i){
			return str[i];
		}
		int getlen(){
			return length;
		}*/
	private:
		char str[MAXLENGTH];
		int length;
};
void String::input(String &s){
	int i;
	for(i=0;cin.get()!='\n'&&i<MAXLENGTH;i++){
		cin.unget();
	cin>>s.str[i];
	}
	s.length =i;
}
void String::output(String &s){
	int i;
	for(i=0;i<s.length;i++)
	cout<<s.str[i];
} 
void String::display(){
	system("cls");
	cout<<"1���ַ��������룺"<<endl;
	cout<<"2���ַ����ĸ�ֵ��"<<endl;
	cout<<"3���ַ��������㣺"<<endl;
	cout<<"4���ַ����������"<<endl;
	cout<<"0���˳�������" <<endl;
	int index;
	cin>>index;
	switch(index){
		case 1:display();
		case 2:display();
		case 3:display();
		case 4:display();
		case 0:break;
		default:cout<<"��Ч���룡";system("pause");display(); 
	}
}
int main(){
	String str;
	str.display();
	return 0;
}
