#include <bits/stdc++.h>
using namespace std;

struct node{
	int prefix, suffix, res;
	node(int _pre = 0,int _suff = 0,int _res = 0): prefix(_pre), suffix(_suff), res(_res){};
};

vector<node> Tree; 
vector<int> a;
int n, q;

node combine(node Left,node Right,int l,int r){
	node cur_node;
	cur_node.res = max(Left.res,Right.res);
	cur_node.prefix = Left.prefix;
	cur_node.suffix = Right.suffix;
	int mid = (l + r) >> 1;
	//cerr << mid << ' ' << a[mid] << ' ' << a[mid + 1] << '\n';
	if (a[mid] != a[mid + 1]){
		cur_node.res = max(cur_node.res,Left.suffix + Right.prefix);
		if (Left.prefix == mid - l + 1) cur_node.prefix = max(cur_node.prefix,Left.prefix + Right.prefix);
		if (Right.suffix == r - mid) cur_node.suffix = max(cur_node.suffix,Right.suffix + Left.suffix);
	}
	return cur_node; 
}

void build(int id,int l,int r){
	if (l == r){
		Tree[id] = node(1,1,1);
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1,l,mid);
	build(id << 1 | 1,mid + 1,r);
	Tree[id] = combine(Tree[id << 1],Tree[id << 1 | 1],l,r);
	
}

void update(int id,int l,int r,int pos){
	if (pos < l || pos > r) return;
	if (l == r){
		a[pos] = 1 - a[pos];
		return;
	}
	int mid = (l + r) >> 1;
	update(id << 1,l,mid,pos);
	update(id << 1 | 1,mid + 1,r,pos);
	Tree[id] = combine(Tree[id << 1],Tree[id << 1 |1],l,r);
}



int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	a.resize(n + 1);
	
	Tree.resize(4*n + 10);
	build(1,1,n);
	
	while (q--){
		int x;
		cin >> x;
		update(1,1,n,x);
		cout << Tree[1].res << '\n';
	}
	return 0;
}
