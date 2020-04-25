#include <iostream>
using namespace std;
int main()
{
	int L,max=0,cnt=0;
	string s,s1,s2,ans;
	int i,j,k;
	int len;
	cin>>L;
	cin>>s;
	len=s.length();
	for(i=L;i<len;i++)
	{
		for(j=0;j+i<len;j++)
		{
			cnt=0;
			s1=s.substr(j,i);
			for(k=0;k+i<len;k++)
			{
				s2=s.substr(k,i);
				if(s1==s2)
					cnt++;
			}
			if(cnt>max)
			{
				ans=s1;
				max=cnt;		
			}
			else if(cnt==max&&s1.length()>ans.length())
			{
				ans=s1;
			}
				
		}
	} 
	cout<<ans<<endl;
	return 0;
} 
