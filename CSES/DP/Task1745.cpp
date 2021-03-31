#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
using namespace std;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;

	int suma = accumulate(all(a),0);
	vector<int> dp(suma + 1,0);

	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = suma; j >= a[i]; j--)
			if (dp[j - a[i]] == 1) dp[j] = 1;
	
	vector<int> ans;
	for (int i = 1; i <= suma; i++)
		if (dp[i]) ans.emplace_back(i);
	cout << ans.size() << '\n';
	for (int x: ans) cout << x << ' ';
	return 0;
}
