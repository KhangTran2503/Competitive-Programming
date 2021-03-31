#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
vector<int> a[N];
set<int> cm[N];
set<int> ans[N];
bool fre[N];
int n,m;

void dfs(int u,int k)
{
    fre[u]=1;
    cm[k].insert(u);
    for (auto v: a[u])
        if (!fre[v]) dfs(v,k);
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    memset(fre,0,sizeof(fre));
    int res=0,cnt=0;
    for(int i=1; i<=n; i++)
    if (!fre[i])
    {
        cnt++;
        dfs(i,cnt);
        if (cm[cnt].size()>1) ans[res++]=cm[cnt];
    }

    for(int i=0; i<=cnt; i++)
        if (cm[i].size()==1) ans[res].insert(*cm[i].begin());
    if (!ans[res].empty())
        cout<<res+1<<'\n';
    else
    {
        cout<<res<<'\n';
        res--;
    }
    for(int i=0; i<=res; i++)
    {
        cout<<ans[i].size()<<'\n';
        //sort(ans[i].begin(),ans[i].end());
        for(auto v: ans[i]) cout<<v<<' ';
        cout<<'\n';
    }
    return 0;
}
