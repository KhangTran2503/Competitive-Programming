/*	2020-12-17	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9)+10;
int n;
vector<int> l;
vector<int> r;
vector<pair<int,int>> seg;

void solve(){
	cin >> n;
	l.assign(n,0);
	r.assign(n,0);
	seg.assign(n,{});
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i], seg[i] = {l[i],r[i]};
	sort(all(l));
	sort(all(r));
	
	/* Each [L,R] => count [l,r] such that r < L or l > R => is number segment need remove */
	int ans = n - 1;
	for (auto &[L,R]: seg){
		int cnt_lef = (int)(lower_bound(all(r),L) - r.begin());
		int cnt_rig = l.end() - upper_bound(all(l),R); 
		ans = min(ans,cnt_lef + cnt_rig);
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