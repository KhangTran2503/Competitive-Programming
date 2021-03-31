#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<pair<int,int>> seg(n);
	for (int i = 0; i < n; i++) cin >> seg[i].second >> seg[i].first;
		
	sort(seg.begin(),seg.end());

	//for (auto s: seg) cout << s.second << ' ' << s.first << '\n';


	int ans = 0;
	set<pair<int,int>> dp;
	dp.insert(make_pair(0,0));
	for (pair<int,int> s: seg){
		auto it = (dp.upper_bound(make_pair(s.second,n + 1)));
		it--;
		int cnt = it->second + 1;
		ans = max(ans,cnt);
		dp.insert(make_pair(s.first,ans));
	}
	cout << ans;
	return 0;
}
