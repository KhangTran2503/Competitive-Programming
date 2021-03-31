/*	2020-12-31	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

void solve(){
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		int flip = ((i % 2)*((n - i + 1) % 2)) % 2;
		if (flip) ans ^= x;
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}