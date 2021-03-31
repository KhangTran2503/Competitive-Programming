#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;


pair<bool,ll> check_prime(ll x){
	if (n == 1) return {false,-1};
	int max_num = -1;
	int num = 0;
	for (ll i = 2; i*i <= x; i++){
		if (x % i == 0){
			int tmp = 0;
			while (x % i == 0){
				tmp ++;
				x /= i;
			}
			if (tmp > max_num){
				max_num = tmp;
				num = i;
			}
		}
	}
	if (max_num > -1) return {false,num};
	return {true,-1};
} 

void solve(){
	cin >> n;
	auto [ok,u] = check_prime(n);
	if (ok) cout << 1 << '\n' << n << '\n';
	else {
		vector<ll> ans;
		while (n % u == 0){
			ans.push_back(u);
			n /= u;
		}
		
		ans.back() *= n;
		cout << (int)ans.size() << '\n';
		for (ll x: ans) cout << x << ' ';
		cout << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}