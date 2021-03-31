#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
using namespace std;
typedef long long ll;
int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<ll> a(n);
    for (ll &ai: a) cin >> ai;

    ll ans = max(*max_element(all(a)) * 2,accumulate(all(a),0LL));
    cout << ans;
    return 0;
}
