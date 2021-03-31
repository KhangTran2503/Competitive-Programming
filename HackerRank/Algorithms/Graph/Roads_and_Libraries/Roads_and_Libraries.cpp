///tim thanh phan lien thong , voi moi tp lien thong dem so dinh la num
///Moi tp lien thong cong thuc la res+=min(num*clib,(num-1)*croad+clib)
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
typedef long long ll;
int n,m,croad,clib,q;
vector<int> g[N];
bool ok[N];


void refesh(int x)
{
    for(int i=1; i<=x; i++) g[i].clear();
}

int dfs(int u)
{
    ok[u]=1;
    //if (g[u].empty()) return 1;
    int cnt=1;
    for (int v: g[u])
     if (!ok[v])
    {
        cnt+=dfs(v);
    }
    return cnt;

}


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>q;
    while (q--)
    {
        cin>>n>>m>>clib>>croad;
        while (m--)
        {
           int x,y;
           cin>>x>>y;
           g[x].push_back(y);
           g[y].push_back(x);
        }

        ll res=0;
        memset(ok,0,sizeof(ok));
        for(int i=1; i<=n; i++)
        if (!ok[i])
        {
            int num=dfs(i);
            if (num==1) res+=(ll)clib;
            else
            {
                if (clib<=croad) res+=(ll)num*(ll)clib;
                else res+=((ll)(num-1)*(ll)croad+(ll)clib);
            }
        }
        cout<<res<<'\n';
        refesh(n);

    }
    return 0;
}
