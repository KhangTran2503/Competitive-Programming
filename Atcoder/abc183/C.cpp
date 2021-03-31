#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, K;
int ans = 0;
vector<int> v;
vector<int> used;
vector<vector<int>> T;

void go(int iter,ll t){
	if (iter == n){
		t += T[v[n - 1]][v[0]];
		if (t == K) ans++;
		return;
	}
	for (int u = 0; u < n; u++)
		if (used[u] == 0){
			used[u] = 1;
			v[iter] = u;
			if (iter > 0) go(iter + 1,t + T[v[iter - 1]][v[iter]]);
			else go(iter + 1,t);
			used[u] = 0;
			v[iter] = -1;
		}
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> K;
	//vector<vector<int>> T(n,vector<int>(n,0));
	T.resize(n,vector<int> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> T[i][j];
	
	v.resize(n);
	used.resize(n);
	used[0] = 1;
	v[0] = 0;
	go(1,0);
	cout << ans;
	return 0;
}
