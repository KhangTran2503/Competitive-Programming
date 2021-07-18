/*	2021-07-17	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
vector<string> a;
int n, m, q;

struct Trie{
	struct node{
		vector<int> next;
		bool leaf = false;
		node(){
			next.assign(26,-1);
		}
	};
	
	vector<node> Nodes;
	int curidx;
	
	Trie(){
		Nodes.emplace_back();
		curidx = 0;
	};
	
	void insert(const string &s){
		int idx = 0;
		for (char ch: s){
			int c = ch - 'a';
			if (Nodes[idx].next[c] == -1){
				Nodes[idx].next[c] = (++curidx);
				Nodes.emplace_back();
			}
			idx = Nodes[idx].next[c];
		}
		Nodes[idx].leaf = true;
	}
	
	bool search(const string &s){
		int idx = 0;
		for (char ch: s){
			int c = ch - 'a';
			if (Nodes[idx].next[c] == -1) return false;
			idx = Nodes[idx].next[c];
		}
		return true;
	}
};



int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> q;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	
	Trie trie;
	string tmp = "";
	// Ngang 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			int len = min(10,m - j);
			trie.insert(a[i].substr(j,len));
		}
	
	for (int j = 0; j < m; j++){
		for (int i = 0; i < n; i++){
			 tmp = "";
			 for (int len = 0; (len < 10) && (i + len < n); len++) tmp.push_back(a[i + len][j]);
			 trie.insert(tmp);
		}
	}
	
	
	string s;
	while (q--){
		cin >> s;
		if (trie.search(s)) putchar('1');
		else putchar('0');
	}
	
	return 0;
}
