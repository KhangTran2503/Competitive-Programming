/*	2020-12-15	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9)+10;
int n, m;
vector<int> a;

void solve(){
	cin >> n >> m;
	a.assign(n,0);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int break_p = n;
	while (break_p > 0 && break_p == a[break_p - 1]) break_p--;
	//cerr << "break point " << break_p << '\n';
	
	double ans;
	if (break_p == 0) ans = 0.0;
	else ans = 1.0;
	for (int i = 0; i < m; i++){
		int r;
		double p;
		cin >> r >> p;
		if (r >= break_p) ans *= (1 - p); 
	}
	ans = 1 - ans;
	cout << fixed << setprecision(7) << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}