#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	sort(a.begin(),a.end());

	int ans = -1;
	int rig = (int)a.size() -1;
	for (int lef = 0; lef < rig; lef++){
		while (rig > lef && a[rig] + a[lef] > m) rig--;
		if (rig <= lef) break;
		ans = max(ans,a[lef] + a[rig]);
		//break;
	} 
	cout << ans;
	return 0;
}
