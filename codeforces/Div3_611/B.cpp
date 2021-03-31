#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        ll n, k;
        cin >> n >> k;
        ll q = (n/k);
        ll r = min(k/2,n % k);
        ll ans = q*(k - r) + r*(q + 1);
        cout << ans << '\n';
    }
    return 0;
}