#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = (ll)(1e9) + 7;
const ll inv2 = 500000004;
vector<ll> pow7(22);
vector<ll> sum(22);
vector<ll> bit7(22);

ll calc_sum(ll u){
	if (u == 0) return ((bit7[u] + 1LL)*(bit7[u] + 2)*inv2) % Mod;
	ll ans = ((bit7[u]*(bit7[u] + 1LL)*inv2) % Mod * sum[u - 1]) % Mod;
	ans = (ans + ((bit7[u] + 1LL)*calc_sum(u - 1)) % Mod) % Mod;
	return ans;  
}


void solve(int t){
    
    ll n;
    cin >> n;
    n++;
    ll u;
    
	ll q = (n)/7LL;
	ll r = (n) % 7LL;
	ll ans = 0;
	if (q > 0){
		u = q - 1;
		for (int i = 0; i < 22; i++){
			bit7[i] = u % 7;
			u /= 7;
		}
		ans = (calc_sum(21)*28LL) % Mod;
	}
	
	ll tmp = r*(r + 1)/2LL;
	if (r > 0){
		u = q;
		while (u){
			tmp = (tmp*(ll)(u % 7 + 1)) % Mod;
			u /= 7LL;
		}
	}
	
	ans = (ans + tmp) % Mod;
    ll all = (inv2*((n % Mod)*((n + 1LL) % Mod) % Mod)) % Mod;
    ans = (all - ans + Mod) % Mod;
    cout << "Case " << t << ": " << ans << '\n';
	
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;

    sum[0] = 28LL;
    for (int i = 1; i < 22; i++) sum[i] = (sum[i-1]*28LL) % Mod;
    for (int i = 1; i <= T; i++) solve(i);
    
    return 0;
}
