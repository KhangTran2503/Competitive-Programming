#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = (ll)(1e9) + 7;
int n, m;
vector<ll> fac, inv_fac;

int fastpow(ll x,ll y){
    ll ans = 1;
    while (y){
        if (y & 1) ans = (ans * x) % Mod;
        x = (x*x) % Mod;
        y >>= 1;
    }
    return ans;
}

void init(){
    fac.assign(n + m,1);
    inv_fac.assign(n + m,1);

    for (int i = 1; i < n + m; i++)
        fac[i] = (fac[i - 1]*i) % Mod;
    
    inv_fac[n + m - 1] = fastpow(fac[n + m - 1],Mod - 2);
    for (int i = n + m - 2; i >= 0; i--)
        inv_fac[i] = (inv_fac[i + 1]*(i + 1)) % Mod;

}

ll nCk(int k,int n){
    ll ans = fac[n];
    ans = (ans*inv_fac[n - k]) % Mod;
    ans = (ans*inv_fac[k]) % Mod;
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    init();
    cout << nCk(n - 1,n + m - 1);
    return 0;
}

