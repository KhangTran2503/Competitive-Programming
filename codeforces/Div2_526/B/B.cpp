#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll s,sum=0,Minx=ll(1e9);

int main()
{
    //cout << "Hello world!" << endl;
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin>>n>>s;
    ll sum=0;
    for(int i=1; i<=n; i++){
        ll x;
        cin>>x;
        sum+=(ll)x;
        Minx = min(Minx,x);
    }
    if (sum<s) cout<<-1;
    else cout<<min(Minx,(sum-s)/(ll)n);
    return 0;
}
