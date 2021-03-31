/*	2020-12-02	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const int INF = (int)(1e9);
vector<ii> a;
int n;

bool check(ll x){
	int i = 0;
	while (i < n && a[i].second <= x) i++;
	if (i == n) return true;
	
	ll cur_min, cur_max;
	cur_min = a[i].second;
	cur_max = a[i].second;
	ll dup_l1;
	for (; i < n; i++){
		cur_min = min(cur_min,a[i].second);
		cur_max = max(cur_max,a[i].second);
		if (cur_max - cur_min > 2*x) break;
		dup_l1 = cur_max + cur_min;
	}
	if (i == n) return true;
	
	ll dup_l2;
	cur_min = a[i].second;
	cur_max = a[i].second;
	for (; i < n; i++){
		cur_min = min(cur_min,a[i].second);
		cur_max = max(cur_max,a[i].second);
		if (cur_max - cur_min > 2*x) break;
		dup_l2 = cur_max + cur_min;
	}
	
	if (i < n) return false;
	return (dup_l2 >= dup_l1);
	
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	a.resize(n);
	ll tmp1 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		a[i].second *= 10LL;
		if (a[i].first == 0) tmp1 = max(tmp1,a[i].second); 
	}
	
	sort(all(a));
	
	ll lo = 0, hi = (ll)(1e10); 
	ll tmp2 = -1;
	while (lo <= hi){
		ll mid = (lo + hi) >> 1;
		if (check(mid)){
			tmp2 = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	ll ans = max(tmp1,tmp2);
	cout << fixed << setprecision(1) << (ans/10.0);
	return 0;
}