#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
using namespace std;
int n, x;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> x;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(all(a));
	int l = -1,r = -1;
	for (int i = 0; i < n; i++){
		auto it	= lower_bound(a.begin() + i + 1,a.end(),make_pair(x - a[i].first,-1));
		if (it == a.end()) continue;
		if (it->first + a[i].first != x) continue;
		l = min(a[i].second,it->second);
		r = max(a[i].second,it->second);
		break;
	}
	
	if (l == -1) cout << "IMPOSSIBLE";
	else cout << l << ' ' << r;
	return 0;
}
