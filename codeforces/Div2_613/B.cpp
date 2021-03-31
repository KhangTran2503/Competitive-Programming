#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)(1e15);
int t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll &i :a) cin >> i;
        ll sum = 0;
        for (ll x: a) sum  += x;

        ll maxsub = -INF;

        ll sumsub = -1;
        for (int i = 0; i < n - 1; i++){
            if (sumsub < 0) sumsub = a[i];
            else sumsub += a[i];
            maxsub = max(maxsub,sumsub);
        }

        sumsub = -1;
        for (int i = 1; i < n; i++){
            if (sumsub < 0) sumsub = a[i];
            else sumsub += a[i];
            maxsub = max(maxsub,sumsub);
        }

        if (maxsub < sum) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}