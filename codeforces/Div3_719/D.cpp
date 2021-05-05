#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> a;

void solve(){
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= (i + 1);
    }

    sort(a.begin(),a.end());
    ll ans = 0;
    for (int i = 0; i < n; ){
        int j = i;
        while (j < n && a[i] == a[j]) j++;
        int cnt = j - i;
        ans += (ll)cnt*(cnt - 1)/2LL;
        i = j;
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
