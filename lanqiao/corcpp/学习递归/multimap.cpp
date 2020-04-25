#include <iostream>
#include <map>
#include <utility>
using namespace std;
multimap<int, int> m;
int main()
{
        m.insert(make_pair(1,2));
        m.insert(make_pair(1,3));
        m.insert(make_pair(2,1));
        auto it_pair = m.equal_range(1);
        for (auto it = it_pair.first; it != it_pair.second; ++it)
        {
                cout << it->first << ":" << it->second << endl; //1:2 1:3
                it->second = 5;
        }
        it_pair = m.equal_range(1);
        for (auto it = it_pair.first; it != it_pair.second; ++it)
                cout << it->first << ":" << it->second << endl;  //1:5 1:5
        return 0; 
}
