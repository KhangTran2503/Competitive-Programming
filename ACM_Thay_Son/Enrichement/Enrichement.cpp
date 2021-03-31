#include <bits/stdc++.h>
#define N 2*int(1e6)+5
using namespace std;
typedef long long ll;
int n,m;
ll a[N];

int id(int x,int y)
{
    return x*m+y;
}
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
         for(int j=1; j<=m; j++)
         {
             ll x;
             cin>>x;
             a[id(i,j)]=x+a[id(i-1,j)]+a[id(i,j-1)]-a[id(i-1,j-1)];
         }

    ll res=ll(1e18);
    for(int i=3; i<=n; i++)
      for(int j=3; j<=m; j++)
    {
        int u=i-3+1,v=j-3+1;
        ll tmp=a[id(i,j)]+a[id(u-1,v-1)]-a[id(i,v-1)]-a[id(u-1,j)];
        res=min(res,tmp);
    }
    cout<<res;
    return 0;
}
