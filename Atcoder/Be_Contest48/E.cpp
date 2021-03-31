#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

ll calc(ll x){
    ll ans = 0;
    while (x){
        ans += (x/5LL);
        x /= 5;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    if (n & 1) cout << 0;
    else cout << (ll)(n/10LL + calc(n/10));
    return 0;
}