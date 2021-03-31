#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll t;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    vector<ll> a(n);
    for (ll &x: a) cin >> x;

    ll ans = 0;
    int rig = 0;
    ll sum = 0;
    for (int lef = 0; lef < n; lef++){
        while (rig < n && sum + a[rig] <= t){
            sum += a[rig];
            ans += (rig - lef + 1);
            rig ++; 
        }
        cout << lef << ' ' << rig << '\n';
        //ans += (rig - lef)*(rig - lef)/2LL;
        sum -= a[lef];
    }
    cout << ans;
    return 0;
}
