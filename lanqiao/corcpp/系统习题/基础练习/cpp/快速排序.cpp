#include <iostream>
using namespace std;
int partition(int n[],int a,int b){
	int i=a,t,x;
	int j=b+1;
	x=n[a];
	while(1){
		while(i<b&&n[++i]<x);
		while(j>a&&n[--j]>x);
		if(i>=j)break;
		t=n[i];
		n[i]=n[j];
		n[j]=t;
	}
	n[a]=n[j];
	n[j]=x;
	return j;
} 
void quicksort(int n[],int a,int b){
	
	if(a<b){
	int t=partition(n,a,b);
	quicksort(n,a,t-1);
	quicksort(n,t+1,b); 
	}
}
int main(){

	int i,n;
	int a[]={6 ,2 ,7 ,3 ,8, 9};
	n=6;
	quicksort(a,0,n-1);
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
} 
