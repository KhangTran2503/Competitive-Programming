#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;

int main()
{
    cin>>n>>k;
    if (k==1) cout<<n;
    else
    {
        int i=0;
        for(;(1LL<<i)<=n; i++){};
        cout<<(1LL<<i)-1;
    }
    return 0;
}
