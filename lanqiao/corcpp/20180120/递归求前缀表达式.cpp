#include <iostream>
#include <cstdlib>
using namespace std;
int exp(); 
int main(){
	
	cout<<exp();
	
	return 0;
} 
int exp(){
	char s[1000];
	cin>>s;
	switch(s[0]){
		case '+' :return  exp()+exp();
		case '-' :return  exp()-exp();
		case '*' :return  exp()*exp();
		case '/' :return  exp()/exp();	
		default : return atoi(s);
		break;
	}
}
