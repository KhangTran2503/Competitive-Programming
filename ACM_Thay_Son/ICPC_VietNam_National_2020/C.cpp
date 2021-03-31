#include <bits/stdc++.h>
using namespace std;
int n, k;

void solve(){
	cin >> n >> k;
	for (int sz = 1; sz <= n; sz++){
		int r = (n % sz);
		int group = n/sz;
		vector<vector<int>> g(group + (r != 0));
		for (int i = 0; i < group; i++){
			for (int j = 0; j < sz; j++) g[i].push_back(i*sz + j);
		}
		
		if (r){
			for (int j = n - r; j < n; j++) g.back().push_back(j);
		}
		vector<pair<int,int>> M, V;
		for (int i = 0; i < group; i++)
			for (int j = 0; j < sz - 1; j++)
				M.push_back({g[i][j] + 1,g[i][j + 1] + 1});
		
		if (r){
			for (int j = 0; j < r - 1; j++)
				M.push_back({g.back().at(j) + 1,g.back().at(j + 1) + 1});
		}	
		
		for (int i = 0; i < group - 1; i++)
			for (int j = 0; j < sz; j++)
				V.push_back({g[i][j] + 1,g[i + 1][j] + 1});
		if (r){
			for (int j = 0; j < r; j++)
				V.push_back({g[group - 1][j] + 1,g[group][j] + 1});
		}			
		
		
		if ((int)V.size() >= k && (int)M.size() >= k){
			cout << "YES\n";
			for (int i = 0; i < k; i++) cout << M[i].first << ' ' << M[i].second << '\n';
			for (int i = 0; i < k; i++) cout << V[i].first << ' ' << V[i].second << '\n';
			return;
		}
		//else cout << "NO\n";
			 
	}
	cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin >> T;
	while (T--) solve();
	return 0;
}