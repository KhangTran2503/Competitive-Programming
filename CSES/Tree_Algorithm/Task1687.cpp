/*	2020-12-19	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
vector<vector<int>> binup;
int n, q;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	binup.assign(n + 1,vector<int> (21,-1));
	for (int i = 2; i <= n; i++){
		int x;
		cin >> x;
		binup[i][0] = x;
	}
	
	for (int k = 1; k <= 20; k++)
		for (int u = 1; u <= n; u++)
			if (binup[u][k - 1] != -1) binup[u][k] = binup[binup[u][k - 1]][k - 1];
	
	while (q--){
		int u, k;
		cin >> u >> k;
		for (int i = 20; i >= 0; i--)
			if ((k >> i) & 1 && u != -1) u = binup[u][i];
		cout << u << '\n'; 
	}
	return 0;
}