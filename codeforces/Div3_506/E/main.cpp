#include <bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
vector<int> a[N];
vector<int> node;
int level[N],par[N],mark[N];
int n;

void dfs(int u)
{
    for(int i=0; i<a[u].size(); i++)
    {
        int v=a[u][i];
        if (v!=par[u])
        {
            level[v]=level[u]+1;
            par[v]=u;
            dfs(v);
        }
    }
    if (level[u]>2) node.push_back(u);
}

//===========================================
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    memset(level,0,sizeof(level));
    memset(mark,0,sizeof(mark));
    dfs(1);

    int res=0;
    for(int i=0; i<node.size(); i++)
    {
        int u=node[i];
        if (!mark[u])
        {
            mark[u]=true;
            res++;
            u=par[u];
            mark[u]=true;
            mark[par[u]]=true;
            for(int i=0; i<a[u].size(); i++) mark[a[u][i]]=true;

        }
    }
    cout<<res;
    return 0;
}
