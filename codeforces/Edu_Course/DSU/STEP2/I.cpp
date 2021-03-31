#include <bits/stdc++.h>
using namespace std;
int n, m;

struct DSU{
	// first  -> parent v in DSU
	// second -> parity of v
	vector<int> par;
	vector<int> parity;
	vector<vector<int>> child;
	
	DSU(int sz){
		par.assign(sz + 1,-1);
		parity.assign(sz + 1,0);
		child.assign(sz + 1,vector<int>());
		for (int i = 1; i <= sz; i++) child[i].push_back(i);
	}
	
	int FindSet(int u){
		if (par[u] < 0) return u;
		return par[u] = FindSet(par[u]);
	}
	
	void Union(int u,int v){
		int U = FindSet(u);
		int V = FindSet(v);
		if (U == V) return;
		if ((int)child[U].size() >  (int)child[V].size()) swap(U,V);
		par[V] += par[U];
		par[U] = V;
		if (parity[u] == parity[v]){
			for (int x: child[U]){
				parity[x] ^= 1;
				child[V].push_back(x);
			}
			child[U].clear();
		}  
		else {
			for (int x: child[U]){
				child[V].push_back(x);
			}
			child[U].clear();
		}
	}
	
	int get_parity(int u){
		return parity[u];
	}
};


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	DSU dsu(n);
	int shift = 0;
	while (m--){
		int type, a, b;
		cin >> type >> a >> b;
		a = (a + shift) % n;
		if (a == 0) a = n;
		b = (b + shift) % n;
		if (b == 0) b = n;
		if (type == 0) dsu.Union(a,b);
		else {
			int pa = dsu.get_parity(a);
			int pb = dsu.get_parity(b);
			if ((pa^pb) == 0){
				cout << "YES\n";
				shift = (shift + 1) % n;
			}
			else {
				cout << "NO\n";
				
			} 
		}
	}
	return 0;
}