#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	if (n > 60) cout << 1;
	else {
		int ans = INF;
		vector<int> prefix_xor(n + 1);
		for (int i = 1; i <= n; i++) prefix_xor[i] = prefix_xor[i - 1]^a[i];
		
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				for (int k = i; k < j; k++){
					int sum1 = prefix_xor[k]^prefix_xor[i - 1];
					int sum2 = prefix_xor[j]^prefix_xor[k];
					if (sum1 > sum2) ans = min(ans,j - i - 1);
				}
		
		if (ans != INF) cout << ans;
		else cout << -1;
	}
	return 0;
}