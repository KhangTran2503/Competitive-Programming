/*	2021-03-31	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int n, q;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	vector<int> a(n + 1);
	vector<ll> sum(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (ll)a[i];
	
	while (q--){
		int u, v;
		cin >> u >> v;
		cout << sum[v] - sum[u - 1] << '\n';
	}
	return 0;
}