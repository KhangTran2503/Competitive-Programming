/*	2021-07-15	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
vector<int> a;
int n;

void solve(){
	cin >> n;
	a.assign(n,0);
	
	for (int &x: a) cin >> x;
	
	auto check = [&](int u,int v)-> int {
		if (v - u  <= 1) return 1;
		for (int i = u; i <= v - 2; i++)
			for (int j = i + 1; j < v; j++)
				for (int k = j + 1; k <= v; k++)
					if (min(a[i],a[k]) <= a[j] && a[j] <= max(a[i],a[k])) return 0;
		return 1;
	};
	
	ll ans = 0;
	for (int len = 1; len < 5; len++)
	for (int i = 0; i < n; i++)
		if (i + len - 1 < n) ans += (ll)check(i,i + len - 1);
	cout << ans << '\n';
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}
