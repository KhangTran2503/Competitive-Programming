///dem so phan tu cua 1 tp lien thong
///dung quy tac nhan
/// res+=tmp*num
/// tmp+=num
#include <bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
typedef long long ll;
int n,p;
vector<int> g[N];
bool ok[N];

ll dfs(int u)
{
    ok[u]=1;
    ll cnt=1;
    for(int v:g[u])
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
    cin>>n>>p;
    while (p--)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(ok,0,sizeof(ok));
    ll res=0;
    ll tmp=0;
    for(int i=0; i<n; i++)
      if (!ok[i])
      {
         ll num=dfs(i);
         res+=(ll)num*(ll)tmp;
         tmp+=(ll)num;
      }
    cout<<res;
    return 0;
}
