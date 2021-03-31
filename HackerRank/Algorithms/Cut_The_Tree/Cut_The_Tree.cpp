#include <iostream>
#include <bits/stdc++.h>
#define N int(1e5)+5
#define oo int(1e9)
using namespace std;
typedef pair<int,int> ii;
vector<ii> e;
int par[N]={0},n,data[N],d[N];
vector<int> a[N];

int dfs(int u)
{
    if (a[u].empty()) return d[u]=data[u];
    for(int i=0; i<a[u].size(); i++)
    {
        int v=a[u][i];
        if (v!=par[u])
        {
            par[v]=u;
            d[u]+=dfs(v);
        }
    }
    d[u]+=data[u];
    return d[u];
}
//============================================
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
   // freopen("Test.INP","r",stdin);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>data[i];
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        e.push_back(ii(u,v));
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1);
    int res=oo;
    for(int i=0; i<e.size(); i++)
    {
       int u=e[i].first,
           v=e[i].second;
       if (u==par[v]) res=min(res,abs(d[1]-2*d[v]));
       else res=min(res,abs(d[1]-2*d[u]));
    }
    cout<<res;
    return 0;
}
