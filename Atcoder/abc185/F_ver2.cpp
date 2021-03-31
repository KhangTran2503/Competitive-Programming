/*	2020-12-14	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9)+10;

template<class T>
T opt(T T1,T T2){return T1^T2;};
template<class T>
struct SegTree{
	private:
		
		vector<T> data;
		vector<T> seg;
		//vector<pair<T,T>> range;
	public:
		int Size;
		SegTree(int sz){
			seg.resize((sz << 2) + 5,0);
			(this->Size) = sz;
		}
		void build_tree(int r,int l = 1,int id = 1){
			if (l == r){
				seg[id] = data[l - 1];
				return;
			}
			int mid = (l + r) >> 1;
			build_tree(mid,l,id << 1);
			build_tree(r,mid + 1,(id << 1)|1);
			seg[id] = opt(seg[id << 1],seg[(id << 1) | 1]);
		}
		SegTree(vector<T> arr){
			(this->Size) = (int)arr.size();
			(this->data) = arr;
			seg.resize((Size << 2) + 5,0);
			this->build_tree(Size);
		}
		
		void update(int pos,T val,int r,int l = 1,int id = 1){
			if (pos < l || pos > r) return;
			if (l == r){
				seg[id] = opt(seg[id],val);
				return;
			}
			int mid = (l + r) >> 1;
			update(pos,val,mid,l,(id << 1));
			update(pos,val,r,mid + 1,(id << 1) | 1);
			seg[id] = opt(seg[id << 1],seg[(id << 1)|1]);
		}
		
		T get(int u,int v,int r,int l = 1,int id = 1){
			if (l > v || r < u) return 0;
			if (u <= l && r <= v) return seg[id];
			int mid = (l + r) >> 1;
			return opt(get(u,v,mid,l,id << 1),get(u,v,r,mid + 1,(id <<1)|1));
		}
};


int n, q;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	SegTree<int> ST(a); 
	while (q--){
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) ST.update(x,y,n);
		else cout << ST.get(x,y,n) << '\n';
	}
	return 0;
}