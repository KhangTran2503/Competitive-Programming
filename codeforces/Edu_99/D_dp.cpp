#include <bits/stdc++.h>
using namespace std;
const int INF = (int)(1e9);
int memo[501][501][501];
vector<int> a;
int n;

void reset(){
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= 500; j++)
			for (int k = 0; k <= 500; k++) memo[i][j][k] = -1;
}

int dp(int idx,int pre,int cur){
	if (idx == n) return 0;
	int &res = memo[idx][pre][cur];
	if (res != -1) return res;
	res = INF;
	if (a[idx] >= pre) res = dp(idx + 1,a[idx],cur);
	if (pre <= cur && a[idx] > cur) res = min(res,dp(idx + 1,cur,a[idx]) + 1);
	return res;
}

void solve(){
	int x;
	cin >> n >> x;
	a.assign(n,0);
	for (int i = 0; i < n; i++) cin >> a[i];
	reset();
	int ans = dp(0,0,x);
	cout << ((ans != INF) ? ans : -1) << '\n';
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
 	return 0;
}