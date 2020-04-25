#include <iostream>
#include <cstdio>
using namespace std;
bool palindromic(string s);
bool iteratorpalindromic(string::iterator a,string::iterator b);
int main()
{
	string s,temp;
	int prefix,middle=1;
	int i,j;
	int sbg;
	freopen("C:\\Users\\ÎÒµÄµçÄÔ\\Desktop\\in.txt","r",stdin);
	cin>>s;
	if(palindromic(s))
	{
		cout<<"1"<<endl;
		cout<<"1"<<" "<<s.length(); 
	}
	else
	{
		int done=0;
		cout<<"3"<<endl;
		for(i=0;i<s.length();i++)
		{
			if(s[i]==s[s.length()-1])
			{
				for(j=i+1;j>=1;j++)
				{
					if(s[j]!=s[s.length()-j])
					{
						done=1;
						break;
					}
				}
				
			}
			if(done)
			{
				sbg=j-i;
				cout<<i+1<<" "<<sbg<<endl;
				break;
			}
		}
	
		i=i+sbg;	
		middle=s.length()-i-sbg;
		temp=s.substr(i,middle);
	//	cout<<temp<<endl;
		string::iterator front,rear;
		front = temp.begin();
		rear = temp.end()-1;	
		if(middle%2)
		{
			while(true)
			{
				if(iteratorpalindromic(front,rear))
				break;
				else
				{
					front++;
					rear--;
					middle=middle-2;
					i++;
				}
			}
			cout<<i<<" "<<middle<<endl;
			cout<<s.length()-sbg+1<<" "<<sbg;
		}
		else
		{
			int pos=i+1,pos2=i;
			int len,len2;
			string::iterator begin,end,mid;
			mid=front+1;
			begin=front;
			end=rear;
			len=len2=middle;
			while(true)
			{
				if(iteratorpalindromic(mid,end))
				break;
				else
				{
					mid++;
					end--;
					len=len-2;
					pos++;
				}
			}
			mid=rear-1;
			while(true)
			{
				if(iteratorpalindromic(begin,mid))
				break;
				else
				{
					begin++;
					mid--;
					len2=len2-2;
					pos2++;
				}
			}
			if(len2>len)
			{
				cout<<pos2<<" "<<len2<<endl;
				cout<<s.length()-sbg+1<<" "<<sbg;
			}
			else
			{
				cout<<pos<<" "<<len<<endl;
				cout<<s.length()-sbg+1<<" "<<sbg;	
			}
		}
		
		
	}	
	
	return 0;
}
bool palindromic(string s)
{
	int cnt=0;
	string::iterator front,rear;
	front = s.begin();
	rear = s.end()-1;
	while(*front==*rear)
	{
		front++;
		rear--;		
		if(cnt==s.length()/2)
		return true;
		cnt++;
	}
	return false;
}
bool iteratorpalindromic(string::iterator a,string::iterator b)
{
	int len=a-b+1;
	int cnt=0;
	while(*a==*b)
	{
		a++;b--;
		if(cnt==len/2)
		return true;
		cnt++;
	}
	return false;
}

/*	done=0;
		for(i=i+sbg;i<s.length()-sbg;i++)
		{
			for(middle=s.length()-i-sbg;middle>=1;middle=middle-2)
			{
				if(middle%2!=1)
				{
					middle--;
					temp=s.substr(i,middle);
					if(palindromic(temp))
					{
						done=1;
						break;
					}
				}
				else
				{
					temp=s.substr(i,middle);
					if(palindromic(temp))
					{
						done=1;
						break;
					}
				}
			}
			if(done)
			{
				cout<<i<<" "<<middle<<endl;
				break;
			}
			
		}
		cout<<middle<<" "<<sbg<<endl;   */
