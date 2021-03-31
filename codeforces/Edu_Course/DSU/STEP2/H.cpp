#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(), (s).rend()
using namespace std;
typedef long long ll;
typedef tuple<int,int,int,int> tup;
const int INF = 2*(int)(1e9);
int n,m ;
ll s;
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
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edges.emplace_back(w,u,v,i);
	}
	
	
	vector<int> visit(m);
	
	sort(rall(edges));
	DSU dsu(n);
	
	for (int i = 0; i < m; i++){
		int u, v, w, idx;
		tie(w,u,v,idx) = edges[i];
		if (dsu.Union(u,v)){
			visit[i] = 1;
		}	
	}
	
	
	vector<int> ans;
	for (int i = m - 1; i >= 0; --i)
		if (visit[i] == 0){
			int u, v, w, idx;
			tie(w,u,v,idx) = edges[i];
			if (s < w) break;
			s -= (ll)w;
			ans.emplace_back(idx + 1);
		}
	
	sort(all(ans));
	
	cout << (int)ans.size() << '\n';
	for (int x: ans) cout << x << ' ';
	return 0;
}
