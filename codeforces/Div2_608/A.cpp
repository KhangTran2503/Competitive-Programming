#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, d, e, f;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> a >> b >> c >> d >> e >> f;
    ll ans = 0;
    for (ll x = 0; x <= min(a,d); x++){
        ll fir = x*e;
        ll sec = min(min(b,d - x),c)*f;
        ans = max(ans,sec + fir);
    }
    cout << ans;
    return 0;
}