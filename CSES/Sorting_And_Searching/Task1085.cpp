#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;

int calc(const vector<ll>& a,ll maxsum){
	int cnt = 0;
	for (int i = 0; i < n; ){
		ll sum = 0;
		cnt++;
		int j = i;
		while (j < n && sum + a[j] <= maxsum){
			sum += a[j];
			j++;
		}
		i = j;
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	vector<ll> a(n);
	for (ll &x: a) cin >> x;

	ll l = *max_element(a.begin(),a.end()), r = accumulate(a.begin(),a.end(),0LL);

	
	ll ans = r;
	while (l <= r){
		ll mid = (l + r) >> 1;
		int cnt = calc(a,mid);
		if (cnt <= k){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans <<'\n';
	//cout << calc(a,5);
	return 0;
}
