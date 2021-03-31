#include <iostream>
#include <bits/stdc++.h>
#define N 505
#define oo int(1e9)
using namespace std;
typedef pair<int,int> ii;
vector<int> a[N];
vector<ii> e;
int num[N],low[N],cnt,res,check[N][N],n,m;
stack<int> st;

void visit(int u,int p)
{
    low[u]=num[u]=++cnt;
    st.push(u);
    for(int i=0; i<a[u].size(); i++)
    {
        int v=a[u][i];
        if (v==p || check[u][v]) continue;
        if (num[v]) low[u]=min(low[u],num[v]);
        else
        {
            visit(v,u);
            low[u]=min(low[u],low[v]);
        }

    }
    if (low[u]>=num[u])
    {
        res++;
        int v;
        do
        {
            v=st.top();
            st.pop();
            num[v]=low[v]=oo;
        }
        while (u!=v);
    }

}


bool check1()
{
    memset(num,0,sizeof(0));
    cnt=0; res=0;
    for(int i=1; i<=n; i++)
      if (!num[i]) visit(i,i);
    return (res==n);
}
//=================================
bool check2()
{
    memset(check,0,sizeof(check));
    for(int i=0; i<e.size(); i++)
    {
       int u=e[i].first, v=e[i].second;
       check[u][v]=1;
       memset(num,0,sizeof(num));
       cnt=0; res=0;
       for(int i=1; i<=n; i++)
       if (!num[i]) visit(i,i);
       if (res==n) return true;
       check[u][v]=0;
    }
    return false;
}
//===============================
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen("Test.INP","r",stdin);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        e.push_back(ii(u,v));
    }
    if (check1()) cout<<"YES";
    else if (check2()) cout<<"YES";
         else cout<<"NO";
    return 0;
}
