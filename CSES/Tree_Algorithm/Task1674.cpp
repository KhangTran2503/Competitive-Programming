/*	2020-12-18	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
vector<vector<int>> g;
vector<int> sub;
int n;

void dfs(int u){
	sub[u] = 1;
	for (int v: g[u]){
		dfs(v);
		sub[u] += sub[v];
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	g.resize(n + 1);
	sub.resize(n + 1);
	for (int i = 2; i <= n; i++){
		int x;
		cin >> x;
		g[x].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) cout << sub[i] - 1 << ' ';
	return 0;
}