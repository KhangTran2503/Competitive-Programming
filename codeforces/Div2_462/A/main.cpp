#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define oo (ll)(1e18)
#define N 55
using namespace std;
int n,m;
ll a[N],b[N];

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=m; i++) cin>>b[i];
    ll ans=oo;
    for (int k=1; k<=n; k++)
    {
        ll res=-oo;
        for(int i=1; i<=n; i++)
           if (i!=k)
              for(int j=1; j<=m; j++) res=max(res,a[i]*b[j]);
        ans=min(ans,res);
    }
    cout<<ans;
    return 0;
}
