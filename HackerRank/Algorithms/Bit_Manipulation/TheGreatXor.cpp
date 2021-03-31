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

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int q;
	cin >> q;
	while (q--){
		ll x;
		cin >> x;
		int LBS = 64 - __builtin_clzll(x);
		ll ans = 0;
		for (int i = 0; i < LBS; i++)
			if (((x >> i) & 1) == 0) ans += (1LL << i);
		cout << ans << '\n';
	}
	return 0;
}