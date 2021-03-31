/*	2020-12-24	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

template<class T>
struct SegTree{
	private:
		int size;
		vector<T> data;
		vector<T> seg;
		vector<T> lazy;
		vector<int> low;
		vector<int> high;
		void __build(int r,int l = 1,int id = 1){
			low[id] = l, high[id] = r;
			if (l == r){
				seg[id] = data[l - 1];
				return;
			}
			int mid = (l + r) >> 1;
			__build(mid,l,id << 1);
			__build(r,mid + 1,(id << 1) | 1);
			seg[id] = seg[id << 1] + seg[(id << 1) | 1];
		}
		void down(int id){
			if (lazy[id] == 0) return;
			seg[id] += lazy[id]*(ll)(high[id] - low[id] + 1);
			if (low[id] != high[id]){
				lazy[id << 1] += lazy[id];
				lazy[(id << 1) | 1] += lazy[id]; 
			}
			lazy[id] = 0;
		}
		
	public:
		SegTree(int sz){
			size =  sz;
			seg.assign((size << 2) + 10,0);
			lazy.assign((size << 2) + 10,0);
			low.assign((size << 2) + 10, 0);
			high.assign((size << 2) + 10, 0);
			data.assign(size,0);
			__build(size);
		}
		SegTree(const vector<T>& arr){
			data = arr;
			size = (int)data.size();
			seg.assign((size << 2) + 10,0);
			lazy.assign((size << 2) + 10,0);
			low.assign((size << 2) + 10, 0);
			high.assign((size << 2) + 10, 0);
			__build(size);
		}
		void update(int u,int v,ll val = 0,int id = 1){
			down(id);
			if (u > high[id] || v < low[id]) return;
			if (u <= low[id] && high[id] <= v){
				lazy[id] = val;
				down(id);
				return;
			}
		
			update(u,v,val,id << 1);
			update(u,v,val,(id << 1) | 1);
			seg[id] = seg[id << 1] + seg[(id << 1) |1];
		}
		
		T get(int u,int v,int id = 1){
			down(id);
			if (u > high[id] || v < low[id]) return 0;
			if (u <= low[id] && high[id] <= v) return seg[id];
			return get(u,v,id << 1) + get(u,v,(id << 1) | 1);
		}
		
		
};	

int n, Time, q;
vector<int> in, out;
vector<ll> val;
vector<vector<int>> g;


void dfs_hld(int u,int p){
	in[u] = ++Time;
	for (int v: g[u]){
		if (v == p) continue;
		dfs_hld(v,u);
	}
	out[u] = Time;
}	


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	val.resize(n + 1);
	in.resize(n + 1);
	out.resize(n + 1);
	g.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> val[i];
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs_hld(1,0);
	SegTree<ll> STree(Time);
	for (int i = 1; i <= n; i++) STree.update(in[i],out[i],val[i]);
	//for (int i = 1; i <= n; i++) cout << STree.get(in[i],out[i]) << '\n';
	
	while (q--){
		int type, s, x;
		cin >> type;
		if (type == 1){
			cin >> s >> x;
			STree.update(in[s],out[s],x - val[s]);
			val[s] = x;
		}
		else {
			cin >> s;
			cout << STree.get(in[s],in[s]) << '\n';
		}
	}
	return 0;
}