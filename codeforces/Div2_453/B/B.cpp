#include <iostream>
#include <bits/stdc++.h>
#define fto(i,x,y) for(int i=(x); i<=(y); i++);
#define ftoit(val,it) for(__typeof(val.begin()) it=val.begin(); it!=val.end(); it++)
#define N int(1e4)+5
#define Name "B"
using namespace std;
vector<int> a[N];
int f[N];
int c[N],n,res;

void dfs(int u,int p)
{
    //if (a[u].size()==1) return;
    ftoit(a[u],it)
    {
        int v=(*it);
        if (v!=p)
        {
            f[v]=f[u];
            if (f[v]!=c[v])
            {
                res++;
                f[v]=c[v];
            }
            dfs(v,u);
        }
    }
}
//==================
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen(Name".INP","r",stdin);
    //freopen(Name".OUT","w",stdout);
    cin>>n;
    for(int i=2; i<=n;i++)
    {
        int x;
        cin>>x;
        a[i].push_back(x);
        a[x].push_back(i);
    }
    for(int i=1; i<=n; i++) cin>>c[i];
    res=1;
    f[1]=c[1];
    dfs(1,0);
    cout<<res;
    return 0;
}
