/*	2021-06-10	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
//const int INF = (int)(1e9) + 10;
const ll INF = (ll)(1e18);
multiset<ll> set_min;
int n, a, b;


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> a >> b;
	vector<ll> x(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		x[i] += x[i - 1];
	}
		
	ll ans = -INF;
	for (int i = 1; i <= n; i++){
		if (i >= b + 1) set_min.erase(set_min.find(x[i - b - 1]));
		if (i >= a){
			set_min.insert(x[i - a]);
			//cout << i << ' ' << x[i] -  *set_min.begin() << '\n';
			ans = max(ans,x[i] - *set_min.begin());
		}
	}
	cout << ans;
	return 0;
}
