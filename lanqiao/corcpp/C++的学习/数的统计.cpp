#include <iostream>
#include <algorithm>
#include <map> 
#include <vector>
using namespace std;
map<int,int> m;
int a[1005];
int cmp(pair<int,int> x ,const pair<int,int> y)
{
	return x.first<y.first;
}

int main()
{
	int i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	pair<map<int,int>::iterator,bool> insertPair;
	for(i=0;i<n;i++)
	{
		insertPair = m.insert(pair<int,int>(a[i],1));
		if(insertPair.second==false)
		{
			m.at(a[i])++;
		}
	}
	vector<pair<int,int> > vec(m.begin(),m.end());
	sort(vec.begin(),vec.end(),cmp); 
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i].first<<" "<<vec[i].second<<endl;
	}
	return 0;
}


