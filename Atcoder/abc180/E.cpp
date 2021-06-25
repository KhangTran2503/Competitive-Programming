/*	2021-06-19	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef tuple<ll,ll,ll> tup;
const ll INF = (ll)(1e15) + 10;
vector<tup> P;
int N;


ll cost(int i,int j){
	return abs(get<0>(P[i]) - get<0>(P[j])) + abs(get<1>(P[i]) - get<1>(P[j])) + max(0LL,get<2>(P[j]) - get<2>(P[i])); 
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	
	P.resize(N);
	for (int i = 0; i < N; i++){
		int x, y, z;
		cin >> x >> y >> z;
		P[i] = make_tuple(x,y,z);
	}
	
	vector<vector<ll>> dp(N,vector<ll> (1 << N,INF));
	
	dp[0][1 << 0] = 0;
	
	int max_mask = (1 << N) - 1;
	
	
	for (int mask = 0; mask <= max_mask; mask++){
		vector<int> visited;
		vector<int> unvisited;
		for (int i = 0; i < N; i++)
			if ((mask >> i) & 1) visited.push_back(i);
			else unvisited.push_back(i);
		
		if (visited.empty() || unvisited.empty()) continue;
		for (int u: visited)
			for (int v: unvisited)
				dp[v][mask | (1 << v)] = min(dp[v][mask | (1 << v)],dp[u][mask] + cost(u,v));
	}
	
	ll ans = INF;
	for (int i = 1; i < N; i++) 
		ans = min(ans,dp[i][max_mask] + cost(i,0));
	
	cout << ans;
	return 0;
}
