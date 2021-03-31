// Use O(n^3)
//
/*	2021-01-08	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
vector<vector<int>> adj_matrix;
vector<int> is_compelete;
vector<int> dp;
int max_msk;
int n, m;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	adj_matrix.resize(n,vector<int> (n));
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj_matrix[u][v] = 1;
		adj_matrix[v][u] = 1;
	}
	
	max_msk = (1 << n);
	is_compelete.assign(1 << n,0);
	for (int msk = 1; msk < max_msk; msk++){
		vector<int> vertex;
		for (int u = 0; u < n; u++)
			if ((msk >> u) & 1) vertex.push_back(u);
		is_compelete[msk] = 1;
		for (int i = 0; i < (int)vertex.size() - 1; i++)
			for (int j = i + 1; j < (int)vertex.size(); j++)
				if (adj_matrix[vertex[i]][vertex[j]] == 0) is_compelete[msk] = 0;
	}
	
	dp.assign(max_msk,INF);
	dp[0] = 0;
	for (int msk = 1; msk < max_msk; msk++){
		if (is_compelete[msk]) dp[msk] = 1;
		for (int submsk = msk; submsk; submsk = (submsk - 1)&msk)
			if (is_compelete[submsk]) dp[msk] = min(dp[msk],1 + dp[msk^submsk]);
		//cout << dp[msk] << ' ';
	}
	//cout << '\n';
	cout << dp[max_msk - 1];
	return 0;
}