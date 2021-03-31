/*	2020-12-13	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const int maxn = 200;
int n, m;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	vector<int> a(m + 1);
	a[0] = 0;
	for (int i =1; i <= m; i++) cin >> a[i];
	a.emplace_back(n + 1);
	sort(all(a));
	int gap = INF;
	
	for (int i = 1; i <= m + 1; i++)
		if (a[i] - a[i - 1] - 1 > 0) gap = min(gap,a[i] - a[i - 1] - 1);
	
	if (gap == INF) cout << 0;
	else {
		ll ans = 0;
		for (int i = 1; i <= m + 1; i++){
			int tmp = a[i] - a[i - 1] - 1;
			ans += (ll)(tmp/gap) + (ll)(tmp % gap != 0);
		}
		cout << ans;
		
	}
	return 0;
}