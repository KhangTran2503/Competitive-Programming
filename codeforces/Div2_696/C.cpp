/*	2021-01-28	*/
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
multiset<int,greater<int>> ms;
vector<int> a;

void solve(){
	cin >> n;
	a.assign(n + n,0);
	for (int i = 0; i < n + n; i++) cin >> a[i];
	sort(all(a));
	for (int i = 0; i < n + n - 1; i++){
		ms.clear();
		//cout << i << '\n';
		for (int j = 0; j < n + n - 1; j++) 
			if (j != i) ms.insert(a[j]);
		vector<ii> ans = {{a[i],a[n + n - 1]}};
		int last = a[n + n - 1];		
		while (!ms.empty()){
			int maxa = *ms.begin();
			ms.erase(ms.begin());
			//cout << last << ' ' << maxa << '\n';
			auto it = ms.find(last - maxa);
			if (it == ms.end()) break;
			ans.push_back({maxa,last - maxa});
			ms.erase(it);
			last = maxa;
		}
		if (ms.empty()){
			cout << "YES\n";
			cout << a[i] + a[n + n - 1] << '\n';
			for (auto &x : ans) cout << x.first << ' ' << x.second << '\n';
			return;
		}
	}
	cout << "NO\n";
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}