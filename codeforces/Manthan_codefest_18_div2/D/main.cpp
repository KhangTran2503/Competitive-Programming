#include <iostream>
#include <bits/stdc++.h>
#define N 2*int(1e5)+5
using namespace std;
int a[N],level[N],par[N],n,pos[N];
vector<int> g[N];


void bfs()
{
    queue<int> q;
    q.push(1);
    level[1]=1;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v=g[u][i];
            if (!level[v])
            {
                par[v]=u;
                level[v]=level[u]+1;
                q.push(v);
            }
        }

    }
}
//====================================
bool check()
{
    if (a[1]!=1) return false;
    for(int i=1; i<=n; i++) pos[a[i]]=i;
    for(int i=1; i<n; i++)
      {
          int u=a[i],v=a[i+1];
          if (level[u]>level[v]) return false;
          if (pos[par[u]]>pos[par[v]]) return false;
      }

    return true;

}
//======================================
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
    for(int i=1; i<=n; i++) cin>>a[i];
    bfs();
    if (check()) cout<<"Yes";
    else cout<<"No";
    return 0;
}
