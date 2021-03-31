#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = (ll)(1e9) + 7;
int n;

int getbit(ll s,int k){
    return  (s >> k) & 1;
}
int main(){

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<ll> bit(70);
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int pos = 0; pos < 60; pos++){
        ll cnt1 = 0;
        for (int i = 0; i < n; i++)
            if (getbit(a[i],pos)) cnt1++;
        bit[pos] = ((ll)(n - cnt1)*cnt1) % Mod;
    }    

    ll ans = 0;
    ll pw2 = 1;
    for (int i = 0; i < 60; i++){
        ans = (ans + (bit[i]*pw2) % Mod) % Mod;
        pw2 = (pw2*2LL) % Mod; 
    }
    cout << ans;
    return 0;
}