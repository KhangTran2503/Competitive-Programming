//  co k maxai voi tan suat
// co k minai voi tan suat                                                                                                                                                                                         
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = (ll)(1e9) + 7;
const int MaxN = int(1e5) + 1;
ll fac[MaxN], inv_fac[MaxN];
int n, k;

ll inv(ll x){
    ll res = 1;
    ll y = Mod - 2;                                                                                   
    while (y > 0){
        if (y & 1) res = (res * x) % Mod;
        x = (x * x) % Mod;
        y >>= 1;
    }
    return res; 
}


void Init(){
    fac[0] = 1;
    for (int i = 1; i < MaxN; i++) fac[i] = (fac[i - 1] * (ll)i) % Mod;
    inv_fac[MaxN - 1] = inv(fac[MaxN - 1]);
    for (int i = MaxN - 2; i >= 0; i--) inv_fac[i] = (inv_fac[i + 1] * (ll)(i + 1)) % Mod;
}

ll nCk(int k,int n){
    ll ans = (fac[n] * inv_fac[k]) % Mod;
    ans = (ans * inv_fac[n - k]) % Mod;
    return ans;
}
int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    ll ans = 0;
    Init();
    for (int i = n - 1; i >= k - 1; i --){
        ll val = (a[i] - a[n - 1 - i] + Mod*Mod) % Mod;
        val = (val * nCk(k-1,i)) % Mod;
        ans = (ans + val) % Mod;
    }
    cout << ans;
    return 0;
}







