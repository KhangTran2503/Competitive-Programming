/*	2020-12-25	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<ll> a(n);
	for (ll &x: a) cin >> x;
	sort(all(a));
	ll ans = 0;
	ll pre = 0;
	for (int i = 0; i < n; i++){
		ans += (ll)a[i]*(i) - pre;
		pre += (ll)a[i];
	}
	cout << ans;
	return 0;
}