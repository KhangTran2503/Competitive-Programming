#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = int(1e5) + 1;
vector<ll> a;
int n;




void solve(){
	cin >> n;
	a.assign(n + 1,1LL);
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	//vector<int> pos_mod(n,-1);
	int ans_len = n + 1;
	map<ll,int> mod_pos;
	
	ll tmp = 1;
	mod_pos[1] = 0;
	for (int i = 1; i <= n; i++){
		if (__gcd(a[i],(ll)n) > 1LL){
			tmp = 1;
			//if (!mod_pos.empty()) 
			mod_pos.clear();
			mod_pos[tmp] = i;
		}
		else{
			tmp = (tmp*a[i]) % (ll)n;
			auto it = mod_pos.find(tmp);
			if (it != mod_pos.end()){
				ans_len = min(ans_len,i - it->second);
				//cout << it->second << '\n';
			}
			mod_pos[tmp] = i;
		}	
	}
	
	
	if (ans_len == n + 1) cout << 0 << '\n';
	else cout << ans_len << '\n';
	
	
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	
	//Log[1] = 0;
	//for (int i = 2; i < Maxn; i++) Log[i] = Log[i >> 1] + 1;
	while (T--) solve();
	return 0;
}
