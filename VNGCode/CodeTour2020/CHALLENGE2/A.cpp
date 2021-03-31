#include <bits/stdc++.h>
using namespace std;
const int Maxn = int(1e5) + 1;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	vector<int> dp(Maxn);
	dp[0] = 0;
	for (int i = 1; i < Maxn; i++){
		int sqrt_i = int(sqrt(i));
		if (sqrt_i*sqrt_i == i) dp[i] = 1;
		else{	
			dp[i] = 0;
			for (int j = 1; j <= sqrt_i; j++)
				if (i >= j*j && dp[i - j*j] == 1){
					dp[i] = 1;
					break;
				}
			dp[i] ^= 1;
		}
	}
	
	int T;
	cin >> T;
	while (T--){
		int n;
		cin >> n;
		if (dp[n] == 1) cout << "A\n";
		else cout << "B\n";
	}
	
	return 0;
}