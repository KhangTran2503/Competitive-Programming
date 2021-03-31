#include <bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
int P[19][N],in[N],out[N],Level[N],n,m,Time=0;
vector<int> g[N];


void dfs(int u)
{
    in[u]=++Time;///thoi gian vao
    for(int v: g[u])
      if (v!=P[0][u])
    {
        P[0][v]=u;
        Level[v]=Level[u]+1;
        dfs(v);
    }
    out[u]=++Time;///Thoi gian ra

}

void Spacetable()
{
    for(int k=1; k<=18; k++)
      for(int i=1; i<=n; i++)
        P[k][i]=P[k-1][P[k-1][i]];

}

int Calc(int u,int v)
{
    if (Level[u]>=Level[v]) return P[0][u];///thi chac chan phai di qa cha[u]
    if (in[v]>=in[u] && in[v]<=out[u])/// neu v la con u thi tim L[u]+1
    {
        for(int k=18; k>=0; k--)
          if (Level[v]-(1<<k)>=Level[u]+1) v=P[k][v];
        return v;

    }
    else return P[0][u];
}

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    Spacetable();
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        cout<<Calc(x,y)<<'\n';
    }
    return 0;
}
