#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, x;
	cin >> n >> x;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] < a[i - 1]){
			for (int j = 0; j < i; j++)
				if (a[j] > x) {
					swap(a[j],x);
					ans ++;
				}
			if (a[i] < a[i - 1]){
				cout << -1 << '\n';
				return;
			}
		}
	cout << ans << '\n';
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}