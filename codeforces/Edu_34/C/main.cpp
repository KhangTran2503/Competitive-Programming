#include <iostream>
#include <bits/stdc++.h>
#define N 5005
using namespace std;
int a[N],n;
vector<int> g[N];
bool fre[N],dd[N];

void dfs(int u)
{
    dd[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if (!dd[v]) dfs(v);
    }
}

int main()
{
    //cout << "Hello world!" << endl;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1; i<n; i++)
    {
        for(int j=i+1; j<=n; j++)
            if (a[i]<a[j] && !fre[j])
        {
            g[i].push_back(j);
            fre[j]=1;
            break;
        }
    }
    int res=0;
    memset(dd,0,sizeof(dd));
    for(int i=1; i<=n; i++)
        if (!dd[i])
    {
        res++;
        dfs(i);
    }
    cout<<res;
    return 0;
}
