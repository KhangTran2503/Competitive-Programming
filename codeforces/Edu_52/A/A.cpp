#include <bits/stdc++.h>
#define  ll long long
using namespace std;

int main()
{
    ll res, s,a,b,c,t;
    cin>>t;
    while(t--)
    {
        res=0;
        cin>>s>>a>>b>>c;
        res+=s/c;
        res+=(ll)(res/a)*b;
        cout<<res<<'\n';
    }
    return 0;
}
