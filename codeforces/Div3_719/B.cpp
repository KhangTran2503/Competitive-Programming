#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    ll ans = 0;
    ll x = 1;
    while (n/x > 0LL){
        ans += min(n/x,9LL);
        x = x*10LL + 1LL;
    }
    cout << ans << '\n';
    
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
