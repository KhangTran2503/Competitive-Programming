#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define N 35
#define oo (ll)(1e18)
#define Name "Test"
using namespace std;
map<ll,ll> dp[N];
int n;
ll L;
ll c[N];

ll cal(int u,ll l)
{
    ll t=dp[u][l];
    if  (t) return t;
    if (u==0 || l==0) return 0;
    if (u==1) return dp[u][l]=(ll)c[u]*l;
    ll res=oo;
    for (int i=0; i<u; i++)
    {
        ll tt=l/(1LL<<i);
        if (tt*(1LL<<i)<l) tt++;
        res=min(res,tt*(ll)c[i+1]);
    }
    for (int i=0; i<u; i++)
    {
        ll tt=l/(1LL<<i);
            res=min(res,c[i+1]*tt+cal(i,l-tt*(1LL<<i)));
    }
    return dp[u][l]=res;

}


int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    //freopen(Name".INP","r",stdin);
    //freopen(Name".OUT","w",stdout);
    cin>>n>>L;
    for(int i=1; i<=n; i++) cin>>c[i];
    cout<<cal(n,L);
    return 0;
}
