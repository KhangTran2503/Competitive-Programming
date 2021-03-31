#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;

	while (t--){
		int n;
		cin >> n;
		vector<vector<int>> cnt_rig(n,vector<int> (n + 1));
		vector<vector<int>> cnt_lef(n,vector<int> (n + 1));
		vector<int> a(n);
		for (int &x: a) cin >> x;

		for (int i = 0; i < n; i++){
			if (i){
				for (int j = 0; j <= n; j++) {
					cnt_lef[i][j] = cnt_lef[i - 1][j];
					cnt_rig[n - i - 1][j] = cnt_rig[n - i][j];
				}
			}	
			cnt_lef[i][a[i]]++;
			cnt_rig[n - i - 1][a[n - i - 1]]++;
		}

		ll ans = 0;
		for (int j = 1; j < n - 2; j++)
			for (int k = j + 1; k < n - 1; k++) ans += (ll)cnt_lef[j - 1][a[k]]*(ll)cnt_rig[k + 1][a[j]];
		cout << ans << '\n';

	}
	return 0;
}
