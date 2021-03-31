/*  find all l, r (r - l >= 2): sum[r - 1] - sum[l] = a[r]^a[l]
 * 
 * 	=> sum[l] <= sum[r] - a[r] <= sum[l] + a[l] + a[r] 
 *  => sum[l] - a[r] <= sum[r] - 2*a[r] <= sum[l] + a[l]
 *  We have: sum[l] - a[r] <= sum[r] - 2*a[r] (every r)
 *  So:
 * 	=> Each r , find l such that: 
 * 			sum[r] - 2*a[r] <= sum[l] + a[l]
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<ll> a(n + 1), sum(n + 1);
	
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	
	set<pair<ll,int>> s;
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		for (auto it = s.rbegin(); it != s.rend(); it++){
			if (sum[i] - 2*a[i] > it->first) break;
			int l = it->second;
			if ((i - l >= 3) && (a[i]^a[l]) == (sum[i] - a[i] - sum[l])) ans++;
		} 
		s.insert({sum[i] + a[i],i});
	}
	cout << ans;
	return 0;
}
