#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define N int(1e5)+5
using namespace std;
ll ans,p;
int k;

ll change(int u)
{
    ll res=(ll)u;
    while (u)
    {
        res=res*10LL+(ll)(u%10);
        u/=10;
    }
    return res;
}
int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>k>>p;
    for(int i=1; i<=k; i++)
    {
        ll u=change(i);
        ans=(ans+u)%p;
    }
    cout<<ans;
    return 0;
}
