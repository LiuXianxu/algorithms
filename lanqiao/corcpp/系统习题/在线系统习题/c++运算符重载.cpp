#include <iostream>
using namespace std;
class zrf_Ratio{
public:
	zrf_Ratio(){}
	zrf_Ratio(int con_a,int con_b){
		a=con_a;
		b=con_b;
		reduce(); 
	}
	void reduce(){
	int x1=a,x2=b,temp;
	if(x1%x2==0){
	a=x1/x2;b=1; 
	return;
	}
	else if(x2%x1==0){
	b=x2/x1;a=1; return;
	}
	if(x1>x2){
	
	while(x1%x2!=0){
		temp=x1%x2;
		x1=x2;
		x2=temp;
	}
	a=a/temp;
	b=b/temp;
	}
	else {
	while(x2%x1!=0){
		temp=x2%x1;
		x2=x1;
		x1=temp;}
	a=a/temp;
	b=b/temp;
		}
	
	}
	/*不变色字符。。。。。。。。错误
	friend ostream& operator<<(ostream& os, const zrf_Ratio& t);//输出最简分数
　　friend istream& operator>>(istream& is, zrf_Ratio& t);
　　friend bool operator==(const zrf_Ratio& x, const zrf_Ratio& y);
　　friend bool operator<(const zrf_Ratio& x, const zrf_Ratio& y);
	变色字符。。。。。。。。。正确，，，，还不能乱复制？只能乖乖敲？*/
	friend ostream& operator<<(ostream& os,const zrf_Ratio& t);
	friend istream& operator>>(istream& is,zrf_Ratio& t);
	friend bool operator==(const zrf_Ratio& x,const zrf_Ratio&y);
	friend bool operator<(const zrf_Ratio& x,const zrf_Ratio&y);
private:
int a,b;	
};
/*void zrf_Ratio::reduce(zrf_Ratio &t){
	int x1=t.a,x2=t.b,temp;
	if(x1%x2==0){
	t.a=x1/x2;t.b=1; 
	return;
	}
	else if(x2%x1==0){
	t.b=x2/x1;t.a=1; return;
	}
	if(x1>x2){
	
	while(x1%x2!=0){
		temp=x1%x2;
		x1=x2;
		x2=temp;
	}
	t.a=t.a/temp;
	t.b=t.b/temp;
	}
	else {
	while(x2%x1!=0){
		temp=x2%x1;
		x2=x1;
		x1=temp;}
	t.a=t.a/temp;
	t.b=t.b/temp;
	}
	
}*/
ostream& operator<<(std::ostream& os,const zrf_Ratio& t){
	os<<t.a<<"/"<<t.b;
	return os;
}
istream& operator>>(std::istream& is, zrf_Ratio& t){
	is>>t.a>>t.b;
	return is;
}
bool operator==(const zrf_Ratio& x, const zrf_Ratio& y){
	return x.a*1.0/x.b==y.a*1.0/y.b;
}
bool operator<(const zrf_Ratio& x, const zrf_Ratio& y){
	return x.a*1.0/x.b<y.a*1.0/y.b;
}
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	zrf_Ratio zrf(a,b),ssh(c,d);
	cout<<"zrf is:"<<zrf<<"; "<<"ssh is:"<<ssh<<endl;
	cout<<"(zrf==ssh) is:"<<(zrf==ssh)<<"; "<<"(zrf<ssh) is:"<<(zrf<ssh);
	return 0;
}
