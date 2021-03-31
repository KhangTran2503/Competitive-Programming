/*	2020-12-25	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int H, W, M;

template<class T>
struct FenwickTree{
	private:
		vector<T> bit;
		vector<T> pre;
		int size;
	public:
		FenwickTree(int sz){
			size = sz;
			bit.assign(size + 1,0);
			pre.assign(size + 1,0);
		}
		void add(int pos,T val){
			for (; pos <= size; pos += (pos & -pos)) bit[pos] += val;
		}
		void update(int pos,T val){
			add(pos,val - pre[pos]);
			pre[pos] = val;
		}
		T get(int pos){
			T ans = 0;
			for (; pos > 0; pos -= (pos & -pos)) ans += bit[pos];
			return ans; 
		}
};


// for evrey i in row => ans += c[i] - 1
// Use BIT caculate all if col[i] = 1 , but row[i] = 0 

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> H >> W >> M;
	vector<int> r(H + 1,W + 1);
	vector<int> c(W + 1,H + 1);
	
	vector<vector<int>> obs(H + 1);
	for (int i = 0; i < M; i++){
		int u, v;
		cin >> u >> v;
		r[u] = min(r[u],v);
		c[v] = min(c[v],u);
		obs[u].push_back(v);
	}
	
	FenwickTree<ll> fen(W);
	
	ll ans = 0;
	for (int i = 1; i < r[1]; i++) ans += (c[i] - 1);
	for (int i = r[1]; i <= W; i++) fen.update(i,1);
	for (int i = 1; i < c[1]; i++){
		ans += fen.get(r[i] - 1);
		for (int v: obs[i]) fen.update(v,1); 
	}	
	cout << ans;
	return 0;
}