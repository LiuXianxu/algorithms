#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=100000+10,oo=100000000,MAXK=10+1;

typedef long long LL;

int N,S,K,fa[MAXN];
int g[MAXN],num[MAXN*2],next[MAXN*2],cost[MAXN*2],tot=1;
LL f[MAXN][MAXK],sum;

inline void read(int &x)
{
  char ch;
  while (ch=getchar(),ch>'9' || ch<'0') ; x=ch-48;
  while (ch=getchar(),ch<='9' && ch>='0') x=x*10+ch-48;
}

inline void addedge(int a,int b,int c) { ++tot; num[tot]=b; next[tot]=g[a]; g[a]=tot; cost[tot]=c; }

void dfs(int x)
{
  for (int i=g[x];i;i=next[i])
    if (num[i]!=fa[x])
    {
      fa[num[i]]=x;
      dfs(num[i]);
      
      for (int a=K;a;--a)
        for (int b=1;b<=a;++b)
          f[x][a]=max(f[x][a],f[x][a-b]+f[num[i]][b]+(LL)(-b+2)*cost[i]);
    }
}

int main()
{
  read(N); read(S); read(K);
  for (int i=1;i<N;++i)
  {
    int x,y,z;
    read(x); read(y); read(z); sum+=z;
    addedge(x,y,z); addedge(y,x,z);
  }
  
  sum=sum+sum;
  dfs(S);
  
  LL ans=oo; ans=ans*ans;
  for (int i=0;i<=K;++i) ans=min(ans,sum-f[S][i]);
  
  cout << ans << endl;
  
  return 0;
}

