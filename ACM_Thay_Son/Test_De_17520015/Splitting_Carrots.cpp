#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> a(n);

	int SumW = 0;
	for (int &x: a){
		cin >> x;
		SumW += x;
	}

	if (SumW & 1){
		cout << 0;
		return 0;
	}
	vector<bool> dp(SumW + 1,false);
	
	dp[0] = 1;

	for (const int &x: a)
		for (int j = SumW; j >= x; j--)
			dp[j] = (dp[j] || dp[j - x]);

	if (!dp[SumW >> 1]){
		cout << 0;
		return 0;
	}

	cout << 1 << '\n';
	while (1){
		for (int i = 0; i < n; i++){
			if (a[i] & 1){
				cout << i  + 1 << '\n';
				return 0; 
			}
			a[i] >>= 1;
		}
	}
	return 0;
}