#include<iostream>

using namespace std;

void an(int n){
    int i;
    for(i=1;i<=n;i++){
        cout<<"sin("<<i;
        if(i!=n && i%2){
            cout<<"-";
        }
        if(i!=n && i%2==0){
            cout<<"+";
        }
    }
     for(i=1;i<=n;i++){
            cout<<")";
        }
}
void sn(int n){
    int i;
    for(i=1;i<n;i++){
        cout<<"(";
    }
    for(i=1;i<=n;i++){
        an(i);
        cout<<"+"<<n-i+1;
        if(i-n){
            cout<<")";
        }
    }
}
int main(){
    //int n;
   // cin>>n;
	//sn(n);
		an(1);
	cout<<endl;	
	an(2);
	cout<<endl;	
	an(3);
	cout<<endl;	
	an(4);
	cout<<endl;
	cout<<endl;
	sn(1);
	cout<<endl;	
	sn(2);
	cout<<endl;	
	sn(3);
	cout<<endl;
	sn(4);	
    return 0;
}
