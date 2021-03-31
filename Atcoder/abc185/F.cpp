/*	2020-12-13	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
const int Maxn = 300005;
int Tree[4*Maxn];
int a[Maxn];
int n, q;

void build(int id,int l,int r){
	if (l == r){
		Tree[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1,l,mid);
	build((id << 1)| 1,mid + 1,r);
	Tree[id] = Tree[id << 1]^Tree[(id << 1)|1];
}

void update(int id,int l,int r,int pos,int val){
	if (pos < l || pos > r) return;
	if (l == r){
		Tree[id] ^= val;
		return;
	}
	int mid = (l + r) >> 1;
	update(id << 1,l,mid,pos,val);
	update((id << 1) | 1,mid + 1,r,pos,val);
	Tree[id] = Tree[id << 1]^Tree[(id << 1)|1];
}

int get(int id,int l,int r,int u,int v){
	if (r < u || l > v) return 0;
	if (l >= u && r <= v) return Tree[id];
	int mid = (l + r) >> 1;
	return get(id << 1,l,mid,u,v)^get((id << 1)|1,mid + 1,r,u,v);
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	for (int i = 1; i <= q; i++){
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) update(1,1,n,x,y);
		else cout << get(1,1,n,x,y) << '\n';
	}
	return 0;
}