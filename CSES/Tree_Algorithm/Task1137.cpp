/*	2020-12-20	*/
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
vector<int> in,out;
vector<ll> w;
int q;

template<class T>
struct SegTree{
	private:
		int size;
		vector<T> seg;
		vector<T> data;
		vector<int> low;
		vector<int> high;
		void __build(int r,int l = 1,int id = 1){
			low[id] = l; high[id] = r;
			if (l == r){
				seg[id] = data[l - 1];
				return;
			}
			int mid = (l + r) >> 1;
			__build(mid,l,id << 1);
			__build(r,mid + 1,(id << 1) | 1);
			seg[id] = seg[id << 1] + seg[(id << 1) | 1];
		}
		
	public:
		SegTree(int sz){
			this->size = sz;
			seg.assign((sz << 2) + 10,0);
			low.assign((sz << 2) + 10 ,0);
			high.assign((sz << 2) + 10,0);
			data.assign(sz + 1,0);
			this->__build(sz);
			
		}
		SegTree(const vector<T>& arr){
			(this->data) = arr;
			(this->size) = (int)arr.size();
			seg.assign((this->size << 2) + 10,2);
			low.assign((size << 2) + 10,0);
			high.assign((size << 2) + 10,0);
			this->__build(size);
		}
		void update(int pos,int val = 1,int id = 1){
			if (pos < low[id] || pos > high[id]) return;
			if (low[id] == high[id]){
				seg[id] = val;
				return;
			}
			update(pos,val,id << 1);
			update(pos,val,(id << 1) | 1);
			seg[id] = seg[id << 1] + seg[(id << 1) | 1];
		}
		
		T get(int u,int v,int id = 1){
			if (v < low[id] || u > high[id]) return 0;
			if (u <= low[id] && high[id] <= v) return seg[id];
			return get(u,v,id << 1) + get(u,v,(id << 1) | 1);
		}
};


int n;
int Time = 0;

void dfs_hld(int u,int p){
	in[u] = ++Time;
	for (const int &v: g[u]){
		if (v == p) continue;
		dfs_hld(v,u);
	}
	out[u] = Time;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	g.resize(n + 1);
	in.resize(n + 1);
	out.resize(n + 1);
	w.resize(n + 1);

	for (int i = 1; i <= n; i++) cin >> w[i];
	
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs_hld(1,0);
	SegTree<ll> STree(Time);
	for (int i = 1; i <= n; i++) STree.update(in[i],w[i]);
	
	
	while (q--){
		int type;
		cin >> type;
		if (type == 1){
			int s, x;
			cin >> s >> x;
			STree.update(in[s],x);
		}
		else {
			int s;
			cin >> s;
			cout << STree.get(in[s],out[s]) << '\n';
		}
	}
	
	//for (int i = 1; i <= n; i++) cout << in[i] << ' ' << out[i] << '\n';
	return 0;
}