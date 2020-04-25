#include <iostream>
using namespace std; 
#define MAX 1000000+5 
int a[MAX]; 
int main() 
{ 	
 	int n = 0, i = 0; 	 
	cin >> n; 	
	for (i = 0; i < n; i++) 	
	{ 		
		int temp = 0; 		
		cin >> temp; 		
		a[temp]++; 	
	} 	 	
	for (i = 0; i < MAX; i++)
	{ 		
		if (0 != a[i]) 		
		{ 		
		  	cout << i << " " << a[i]; 
		  	cout << endl; 				  
		} 	
	} 	
	return 0;
}

