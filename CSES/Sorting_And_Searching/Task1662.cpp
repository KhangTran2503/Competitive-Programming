#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)(1e9);
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	ll Base = (INF/n + 1)*n;

	map<ll,int> d;
	d[0]++;
	ll sum = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		int ai;
		cin >> ai;
		sum = (sum + ai + Base) % n;
		ans += d[sum];
		d[sum]++;
	}
	cout << ans;
	return 0;
}
