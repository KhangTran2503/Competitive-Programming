#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,M;

ll Pow(ll x,ll y)
{
    x%=M;
    ll res=1;
    while(y>1)
    {
        if (y&1) res=(res*(x%M))%M;
        x=((x%M)*(x%M))%M;
        y>>=1;
    }
    return res%M;
}


ll Phi(ll x)
{
    ll res=x;
    for(ll i=2; i*i<=x; i++)
      if (x%i==0)
      {
          res-=res/i;
          while (x%i==0) x/=i;
      }
    if (x>1) res-=res/x;
    return res;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>a>>b>>c>>M;
    ll ans=(Pow(a,b)*Pow(c,Phi(M)-1))%M;
    cout<<ans;

}
