/*	2021-03-31	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

template <class T>
struct SegTree{
	private:
		vector<int> data;
		vector<int> L;
		vector<int> R;
		vector<T> seg;
		int size;
		void __build(int id,int l,int r){
			L[id] = l;
			R[id] = r;
			if (l == r){
				seg[id] = data[l - 1];
				return;
			}
			int mid = (l + r) >> 1;
			this->__build(id << 1,l,mid);
			this->__build((id << 1) | 1,mid + 1,r);
			this->seg[id] = this->seg[id << 1] + this->seg[(id << 1) | 1];
		}
		
		
		void __update(int pos,int val,int id = 1){
			if (pos < L[id] || pos > R[id]) return;
			if (L[id] == R[id]){
				seg[id] = val;
				return;
			}
			__update(pos,val,id << 1);
			__update(pos,val,id << 1 | 1);
			seg[id] = seg[id << 1] + seg[(id << 1) | 1];
		}
		
		T __get(int u,int v,int id = 1){
			if (this->L[id] > v || this->R[id] < u) return 0;
			if (u <= L[id] && R[id] <= v) return seg[id];
			return __get(u,v,id << 1) + __get(u,v,(id << 1) | 1);
		}
		
	public:
		SegTree(vector<int> a){
			this->size = (int)a.size();
			this->data = a;
			this->L.resize(4*this->size + 5);
			this->R.resize(4*this->size + 5);
			this->seg.resize(4*this->size + 5);
			this->__build(1,1,this->size);
		}
		void update(int pos,int val){
			this->__update(pos,val);
		}
		
		T get(int u,int v){
			return this->__get(u,v);
		} 
		
		
};


int n, q;
vector<int> x;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	x.resize(n);
	for (int &xi: x) cin >> xi;
	
	SegTree<ll> seg(x);
	
	
	while (q--){
		int type, u, v;
		cin >> type >> u >> v;
		if (type == 1) seg.update(u,v);
		else cout << seg.get(u,v) << '\n';
	}
	return 0;
}