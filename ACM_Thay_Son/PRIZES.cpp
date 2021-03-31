#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    
    vector<ll> a(n + 1,0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }

    vector<ll> max_lef(n - k + 3,0);
    vector<ll> max_rig(n - k + 3,0);
    max_lef[0] = 0;
    max_rig[n - k + 2] = 0;

    for (int i = k; i <= n; i++){
        max_lef[i - k + 1] = a[i] - a[i - k];
        max_rig[i - k + 1] = a[i] - a[i - k];
    }

    for (int i = 1; i <= n - k + 1; i++){
        max_lef[i] = max(max_lef[i],max_lef[i - 1]);
        max_rig[n - k + 2 - i] = max(max_rig[n - k + 2 - i],max_rig[n - k + 3 - i]);
    }
    
    

    ll ans = (ll)(1e18);
    for (int i = 1; i <= n - k + 1; i++){
        ll tmp = 0;
        if (i > k) tmp = max(max_lef[i - k],tmp);
        if (i  + k <= n - k + 1) tmp = max(max_rig[i + k],tmp);
        ll sumi = a[i + k - 1] - a[i - 1];
        if (sumi >= tmp) ans = min(ans,sumi);
    }
    cout << ans;
    return 0;
}
