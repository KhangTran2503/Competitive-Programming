#include <bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
typedef long long ll;
vector<int> g[N];
int f[N],h[N],n,m,maxdis;
ll res;

void dfs(int u)
{
    if (g[u].empty())
    {
        h[u]=f[u]=1;
        return;
    }

    vector<int> fval;
    for(int v: g[u])
    {
        dfs(v);
        fval.push_back(h[v]);
    }
    sort(fval.begin(),fval.end());
    h[u]=fval[fval.size()-1]+1;
    if (fval.size()>1)
    {
        f[u]=1+fval[fval.size()-1]+fval[fval.size()-2];
    }
    maxdis=max(maxdis,max(f[u],h[u]));

}


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;
    for(int i=2; i<=n; i++)
    {
        int x;
        cin>>x;
        g[x].push_back(i);
    }
    dfs(1);
    ll res=(ll)h[1]*(ll)(m-1)*2LL+(ll)maxdis;
    cout<<res;
    return 0;
}
