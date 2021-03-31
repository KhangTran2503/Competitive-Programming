#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, s, k;

ll find(ll high,ll x){
	ll low = 1;
	ll res = -1;
	while (low <= high){
		ll mid = (low + high) >> 1;
		if (mid*(mid - 1)/2 <= x){
			res = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	return res;
}



int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k >> s;
	
	s -= n*(n - 1)/2;
		ll a0 = -1;
		ll cnt = 0;
		for (int i = 0; i < n; i++){
			ll ns = s + (k + 1)*(ll)i;
			if (ns >= 0 && ns % n == 0){
				a0 = ns/n;
				cnt = i;
				break;
			}
		}
		
		if (a0 == -1) cout << -1;
		else {
			//cout << cnt << '\n';
			ll can = 0;
			vector<ll> len;
			while (cnt > 0){
				ll x = find(n,s);
				//cout << x << '\n';
				can += x;
				len.emplace_back(x);
				cnt -= x*(x - 1)/2;
			} 
			//cout << cnt << '\n';
			if (can > n){
				cout << -1;
				return 0;
			}
			vector<ll> ans(n);
			iota(ans.begin(),ans.end(),a0);
			int i = 0;
			for (int l: len){
				int j = i + 1;
				while (j < i + l) ans[j++] -= (k + 1);
				i = j;
			}
			for (int x: ans) cout << x << ' ';
		}

	return 0;
	
}
