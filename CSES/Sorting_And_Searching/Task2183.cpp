#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;

    ll ans = 1;
    sort(a.begin(),a.end());
    
   // for (int x: a) cout << x << ' ';
   // cout << '\n';
    for (int i = 0; i < n && ans >= a[i]; i++) {
      // cout << ans << ' ';
       ans += (ll)a[i];
       // cout << ans << '\n';
    }
    cout << ans;
    return 0;
}
