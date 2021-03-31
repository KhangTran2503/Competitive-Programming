// dp[i][add: 0..1][sub: 0..1] la do dai duong di ngan nhat 1-> n ma
// da chon trang thai xoa va bo
/*	2021-01-23	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const ll INF = (ll)(1e18) + 10;
const int Maxn = 2*int(1e5) + 10;
int n, m;
ll dis[Maxn][2][2];

struct state{
	int u;
	int add, sub;
	state(int _u,int _add,int _sub): u(_u),add(_add),sub(_sub){}
	bool operator < (const state& o) const{
		return u < o.u;
	} 
};

typedef pair<ll,state> PState;
vector<vector<ii>> g;
priority_queue<PState,vector<PState>,greater<PState> > pq;


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}
	
	for (int i = 1; i <= n; i++)
		for (int add = 0; add < 2; add++)
			for (int sub = 0; sub < 2; sub++) dis[i][add][sub] = INF;
	
	
	for (int s = 0; s < 2; s++){
		dis[1][s][s] = 0;
		pq.push({0,state(1,s,s)});
	}
	
	while (!pq.empty()){
		state node = pq.top().second;
		ll d_u = pq.top().first;
		pq.pop();
		if (d_u != dis[node.u][node.add][node.sub]) continue;
		for (ii wv: g[node.u]){
			ll w = wv.first;
			int v = wv.second;
			for (int add = 0; add < 2; add++)
				for (int sub = 0; sub < 2; sub++){
					if ((add & node.add)) continue;
					if ((sub & node.sub)) continue;
					ll val = d_u + w;
					if (add) val += w;
					if (sub) val -= w;
					if (val < dis[v][add | node.add][sub | node.sub]){
						dis[v][add | node.add][sub | node.sub] = val;
						pq.push({val,state(v,add|node.add,sub|node.sub)});
					}
				}
		}
	}
	
	for (int i = 2; i <= n; i++) cout << dis[i][1][1] << ' ';
	
	return 0;
}