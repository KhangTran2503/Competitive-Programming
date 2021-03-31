#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

void solve(ll low,ll high){
    ld ans = 0.0;
    for (ll i = low; i <= high; i++){
        ld num = 3*pow(i*i,1.0/3);
        ans += (1.0/num);
    }

    //cout << ans << '\n';
    int cnt = 15;
    while (ans < 1){
        cnt++;
        ans *= 10;
    }
    cout << fixed << setprecision(5) << ans << "E-0" << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll low, high;
    while (cin >> low >> high) {
        if (low == 0) break;
        solve(low,high);
    }
    return 0;
}
