/*	2021-06-30	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const ll Mod = (ll)(1e9) + 7;
int N;
vector<ll> a;

template<class T> 
void add(T &x, T y){
	x %= static_cast<T>(Mod);
	y %= static_cast<T>(Mod);
	x = (x +  y) % static_cast<T>(Mod);
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	vector<ll> A(N + 1);
	
	// prefixsum
	for (int i = 1; i <= N; i++){
		cin >> A[i];
		A[i] += A[i - 1];
	}
	
	
	vector<vector<ll>> dp(N + 1,vector<ll> (N + 1));
	vector<vector<ll>> memo(N + 2,vector<ll> (N + 2));
	
	dp[0][1] = 1;
	memo[1][0] = 1;
	for (int i = 1; i <= N; i++){
		for (int len = i; len >= 1; len--) {
			ll cur = memo[len][A[i] % len];
			dp[i][len] = cur;
			add(memo[len + 1][A[i] % (len + 1)],dp[i][len]);
		}
	}
	
	ll ans = 0;
	for (int len = 1; len <= N; len++) add(ans,dp[N][len]);
	cout << ans;
	return 0;
}
