#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	vector<ll> a(n);
	for (ll &x: a) cin >> x;
	sort(a.rbegin(),a.rend());
	
	priority_queue<ll> pq;
	for (int i = 0; i <= k; i++) pq.push(0);
	
	ll ans = 0;
	ll sum;
	for (ll x: a){
		sum = pq.top();
		ans += sum;
		pq.pop();
		pq.push(sum + x);
	}
	cout << ans;
	return 0;
}