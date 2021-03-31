#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<pair<int,int>> seg(2*n);
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		seg[i] = make_pair(a,0);
		seg[i + n] = make_pair(b,1);
	}
		
	sort(seg.begin(),seg.end());
	//for (int i = 0; i < 2*n; i++) cout << seg[i].first << '\n';
 	//for (auto s: seg) cout << s.second << ' ' << s.first << '\n';
	int ans = 0;
	int cnt_intersection = 0;
	for (auto s: seg){
		if (s.second == 0) cnt_intersection++;
		else cnt_intersection--;
		ans = max(ans,cnt_intersection);
	}
	cout << ans;
	return 0;
}
