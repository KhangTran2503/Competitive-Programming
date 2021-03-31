#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int nbit = log2(n) + ((n & (n - 1)) != 0);
	
	
	//nbit = 31 - __builtin_ctz(n);
	vector<vector<int>> res(nbit);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < nbit; j++)
			if ( ((i >> j) & 1) == 0) res[j].emplace_back(i + 1);
	cout << nbit << '\n';
	for (int i = 0; i < nbit; i++){
		cout << (int)res[i].size() << ' ';
		for (int x: res[i]) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}
