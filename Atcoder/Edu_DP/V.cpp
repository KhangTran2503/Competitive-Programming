/*	2020-12-08	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
vector<vector<int>> g;
vector<ll> ans;
vector<ll> f_up,f_down;
vector<int> par;
//vector<ll> prefix,suffix;
int n;
ll M;

void dfs_down(int u,int p){
	f_down[u] = 1;
	//ans[u] = 1;
	for (int v: g[u]){
		if (v == p) continue;

		dfs_down(v,u);
		f_down[u] *= (f_down[v] + 1);
		f_down[u] %= M;
	}
	
}
void dfs_up(int u,int p){
	
	vector<ll> lefchild;
    vector<ll> rigchild;
    vector<int> child;
    for (int v: g[u])
        if (v != p){
            lefchild.push_back((f_down[v] + 1) % M);
            child.push_back(v);
        }
    rigchild = lefchild;
    int m = (int)lefchild.size();
    for (int i = 1; i < m; i++) lefchild[i] = (lefchild[i]*lefchild[i - 1]) % M;
    for (int i = m - 2; i >= 0; i--) rigchild[i] = (rigchild[i + 1]*rigchild[i]) % M;
    
    for (int i = 0; i < m; i++){
        int v = child[i];
        ll tmp = 1LL;
        tmp *= (f_up[u]);
        f_up[v] %= M;
        if (i > 0) {
			tmp *= lefchild[i - 1];
			tmp %= M;
		}
        if (i < m - 1){
			tmp *= rigchild[i + 1];
			tmp %= M;
		}
		f_up[v] = (tmp + 1) % M;
    }
    for (int v: child) dfs_up(v,u);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> M;
	g.resize(n);
	ans.resize(n);
	//Size.resize(n);
	//par.assign(n,-1);
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	f_up.assign(n,1);
	f_down.assign(n,1);
	dfs_down(0,-1);
	dfs_up(0,-1);
	
	for (int u = 0; u < n; u++) cout << (f_up[u]*f_down[u])%M << '\n';
	return 0;
}