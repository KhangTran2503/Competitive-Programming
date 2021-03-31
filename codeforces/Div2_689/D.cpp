/*	2020-12-15	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9)+10;
int n, q;
vector<int> a;
vector<ll> prefix;
set<ll> all;
void calc(int l,int r){
	if (l > r) return;
	all.insert(prefix[r] - prefix[l - 1]);
	if (a[l] == a[r]) return;
	int mid = (a[l] + a[r]) >> 1;
	int pos = upper_bound(a.begin() + l,a.begin() + r,mid) - a.begin() - 1;
	//cerr << "pos " << pos << '\n';
	calc(l,pos);
	calc(pos + 1,r);
}

void solve(){
	cin >> n >> q;
	a.assign(n + 1,0);
	prefix.assign(n + 1,0);
	all.clear();
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1,a.end());
	for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + (ll)a[i];
	calc(1,n);
	
	for (int i = 0; i < q; i++){
		ll s;
		cin >> s;
		if (all.find(s) != all.end()) cout << "Yes\n";
		else cout << "No\n";
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}