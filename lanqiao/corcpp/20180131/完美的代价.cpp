#include <iostream>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n>>s;
	int end = n-1;
	int cnt = 0;
	int OldNum = 0;
	for(int i=0;i<end;i++)
	{
		for(int j=end;j>=i;j--)
		{
			
			if(j==i)
			{
				if(n%2==0||OldNum==1)
				{
					cout<<"Impossible";
					return 0;
				}
				OldNum=1;
				cnt += n/2 -i;
				
			}
			else if(s[i]==s[j])
			{
				for(int k=j;k<end;k++)
				{
					swap(s[k],s[k+1]);
					cnt++;
				}
				end--;
				break;
			}	
		}
	}
	cout<<cnt;	
	return 0;
}
