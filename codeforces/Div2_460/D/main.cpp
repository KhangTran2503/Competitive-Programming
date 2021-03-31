#include <iostream>
#include <bits/stdc++.h>
#define N 3*int(1e5)+5
using namespace std;
set<int> a[N];
int n,m;
int color[N],fre[N],dp[30][N];
vector<int> topo;
char c[N];

bool find_clycle(int u)
{
    color[u]=1;
    for (__typeof(a[u].begin()) it=a[u].begin(); it!=a[u].end(); it++)
    {
        int v=(*it);
        if (!color[v])
        {
            if (find_clycle(v)) return true;
        }
        else if (color[v]==1) return true;

    }
    color[u]=2;
    return false;
}
//================================
void dfs(int u)
{
     fre[u]=false;
     for (__typeof(a[u].begin()) it=a[u].begin(); it!=a[u].end(); it++)
     {
        int v=(*it);
        if (fre[v]) dfs(v);
     }
     topo.push_back(u);

}
//===================================
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>c[i];
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        if (x==y)
        {
            cout<<-1;
            return 0;
        }
        a[x].insert(y);
    }

    for(int u=1; u<=n; u++)
      if (find_clycle(u))
      {
          cout<<-1;
          return 0;
      }
    memset(fre,1,sizeof(fre));
    for(int i=1; i<=n; i++)
        if (fre[i]) dfs(i);
    reverse(topo.begin(),topo.end());
    int res=0;
    for(int i='a'; i<='z'; i++)
    {
        for(int u=1; u<=n; u++) dp[i-'a'][u]=(i==c[u]);
        for(int h=0; h<topo.size(); h++)
        {
            int u=topo[h];
            for (__typeof(a[u].begin()) it=a[u].begin(); it!=a[u].end(); it++)
            {
                int v=(*it);
                dp[i-'a'][v]=max(dp[i-'a'][v],dp[i-'a'][u]+(i==c[v]));
            }
        }
        for(int u=1; u<=n; u++) res=max(res,dp[i-'a'][u]);
    }
    cout<<res;
    return 0;
}
///find_clycle : tim chu trinh
/// dp[i][u] là nhận đc giá trị lớn nhất theo i cua dinh u
