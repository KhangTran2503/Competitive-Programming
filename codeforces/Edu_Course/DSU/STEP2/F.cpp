#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
using namespace std;
typedef tuple<int,int,int> tup;
const int INF = 2*(int)(1e9);
int n,m ;
vector<tup> edges;


struct DSU{
	private:
		int size;
	public:
		vector<int> par;
		DSU(int sz){
			(this->size) = sz;
			par.resize(sz + 1,-1);
		}
		
		void reset(){
			par.assign(size + 1,-1);
		}
		
		int FindSet(int u){return (par[u] < 0) ? u : par[u] = FindSet(par[u]);}
		
		bool Union(int u,int v){
			u = FindSet(u);
			v = FindSet(v);
			if (u == v) return false;
			if (par[u] < par[v]) swap(u,v);
			par[v] += par[u];
			par[u] = v;
			return true; 
		}
		
	
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edges.emplace_back(w,u,v);
	}
	sort(all(edges));
	
	DSU dsu(n);
	int ans = INF;
	int num_e = 0;
	int min_e = INF;
	int max_e = -INF;
	for (int i = 0; i <= m - n + 1; i++){
		num_e = 0;
		min_e = INF;
		max_e = -INF;
		for (int j = i; j < m; j++){
			int u, v, w;
			tie(w,u,v) = edges[j];
			if (dsu.Union(u,v)){
				num_e++;
				min_e = min(min_e,w);
				max_e = max(max_e,w);
			}
		}
		if (num_e == n - 1) ans = min(ans,max_e - min_e);
		dsu.reset();
	}
	if (ans != INF){
		cout << "YES\n";
		cout << ans;
	}
	else cout << "NO";
	return 0;
}
