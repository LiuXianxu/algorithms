#include <iostream> 
int main(int argc,char **argv)
{
	std::cout<<"Hello World!"<<std::endl;
	std::cout<<*argv<<std::endl;
	std::cout<<**argv<<std::endl;
	std::cout<<argc<<std::endl;
	return 0;
}
