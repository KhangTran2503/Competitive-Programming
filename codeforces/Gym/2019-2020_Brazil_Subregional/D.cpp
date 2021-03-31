/*#####################
  #	@author:trankhang #
  #	2020-12-01		  #
  #####################*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
int n, k;
vector<vector<int>> g;
vector<int> a;
vector<int> max_len;
vector<int> candidate;


void dfs1(int u,int par){
	max_len[u] = 1;
	for (int &v: g[u]){
		if (v == par) continue;
		dfs1(v,u);
		max_len[u] = max(max_len[u],max_len[v] + 1);
	}
}

void dfs2(int u,int par,int sum){
	int max_child = -1;
	if (u != 1){
		if ((int)g[u].size() == 1){
			candidate.push_back(sum);
			return;
		}
	}
	for (int v: g[u]){
		if (v == par) continue;
		if (max_child == -1 || max_len[max_child] < max_len[v]) max_child = v;
	}
	
	dfs2(max_child,u,sum + 1);
	for (int v: g[u]){
		if (v == par || v == max_child) continue;
		dfs2(v,u,1);
	}
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k;
	g.resize(n + 1);
	a.resize(n + 1);
	max_len.resize(n + 1);
	for (int i = 1; i < n; i++){
		int x;
		cin >> x;
		g[x].push_back(i + 1);
		g[i + 1].push_back(x);
	}
	
	dfs1(1,0);
	dfs2(1,0,1);
	sort(rall(candidate));
	//for (int x: candidate) cout << x << ' ' ;
	cout << '\n';
	ll ans = 0;
	for (int i = 0; i < (int)candidate.size(); i++){
		if (i >= k) break;
		ans += (ll)candidate[i];
	}
	cout << ans;
	return 0;
}