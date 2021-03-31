#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
using namespace std;
typedef tuple<int,int,int> tup;
typedef long long ll;
const int INF = int(1e9);


int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<tup> seg(n);
	for (int i = 0; i < n; i++){
		int a, b, p;
		cin >> a >> b >> p;
		seg[i] = make_tuple(b,a,p);
	}

	sort(all(seg));
	
	set<pair<int,ll>> dp;
	dp.insert({0,0});

	ll maxdp = 0;
	for (int i = 0; i < n; i++){
		int a,b,p;
		tie(b,a,p) = seg[i];
		ll sumdp = prev(dp.lower_bound({a,-INF}))->second;
		maxdp = max(maxdp,sumdp + (ll)p);
		dp.insert({b,maxdp});
	}

	cout << prev(dp.end())->second;
	return 0;
}
