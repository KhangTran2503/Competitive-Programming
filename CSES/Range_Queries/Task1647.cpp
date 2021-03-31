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

/* Using RMQ
 *
 * 
 */
 
int n, q;
vector<vector<int>> ST;
vector<int> x;

void init(){
	for (int i = 1; i <= n; i++) ST[i][0] = x[i];
	for (int k = 1; k < 20; k++)
		for (int i = 1; i + (1 << k) - 1 <= n; i++)
			ST[i][k] = min(ST[i][k - 1],ST[i + (1 << (k - 1))][k - 1]);
}

int get(int u,int v){
	int len = log2(v - u + 1);
	return min(ST[u][len],ST[v - (1 << len) + 1][len]);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	x.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> x[i];
	
	ST.assign(n + 1,vector<int> (20));
	init();
	while (q--){
		int u, v;
		cin >> u >> v;
		cout << get(u,v) << '\n';
	}
	return 0;
}