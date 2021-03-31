/*	2020-12-13	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> tup; 
const int INF = (int)(1e9);
int n;

/* sort increasing w + s
 * => knapsack <= w[i] + s[i] , each i <= N
 * => max for all i
 */ 

struct Block{
	int w,s,v;
	Block(int _w = 0,int _s = 0,int _v = 0): w(_w),s(_s),v(_v){};
	bool operator < (const Block& o) const{
		return s + w < o.s + o.w;
	}
};

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<Block> a(n + 1);
	for (int i = 1; i <= n; i++){
		int w, s, v;
		cin >> w >> s >> v;
		a[i] = Block(w,s,v);
	}	
	
	sort(all(a));
	vector<ll> dp(a[n].w + a[n].s + 1,0);
	for (int i = 1; i <= n; i++){
		for (int j = a[i].s + a[i].w; j >= 1; j--)
			if (j >= a[i].w) dp[j] = max(dp[j],dp[j - a[i].w] + (ll)a[i].v);
	}
	cout << *max_element(all(dp));
	return 0;
}