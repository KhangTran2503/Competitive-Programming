/*	2021-04-23	*/
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
vector<int> a;
vector<vector<int>> Map;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	a.resize(n + 1);
	Map.resize(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		Map[a[i]].push_back(i);
	}
	
	
	std::random_device rd;
	std::mt19937 mt(rd());
	while (q--){
		int l, r;
		cin >> l >> r;
		// Randomized algorithm
		// P_success = 1 - (1/2)^n 
		
		std::uniform_int_distribution<int> distrib(l,r);
		int ans = 1;
		for (int i = 0; i < 50; i++){
			int p = distrib(mt);
			int cnt = upper_bound(all(Map[a[p]]),r) - lower_bound(all(Map[a[p]]),l);
			ans = max(ans,max(2*cnt - (r - l + 1),1));
		}
		cout << ans << '\n';
	}
	return 0;
}