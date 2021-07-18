/*	2021-07-05	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
string N;
ll K;
unordered_map<ll,ll> memo[20];
int n;


ll dp(int pos,bool pre0,bool low,ll prod){
	if (pos == n) {
		if (pre0) return 0LL;
		return (prod <= K);
	}
	
	if ((memo[pos].find(prod) != memo[pos].end()) && (low) && (!pre0)) return memo[pos][prod];
	
	ll ans = 0;
	int max_digit = (low) ? 9 : N[pos] - '0';
	//cout << pos << ' ' << max_digit << '\n';
	for (int d = 0; d <= max_digit; d++){
		// 
		bool new_pre0 = (pre0 && (d == 0));
		
		ll new_prod;
		
		if (new_pre0) new_prod = prod;
		else new_prod = prod * (ll)(d); 
		
		ans += dp(pos + 1,new_pre0,low || (d < max_digit),new_prod);
	
	}
	
	if (!pre0) memo[pos][prod] = ans;
	return ans;
	
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> K;
	n = N.size();
	cout << dp(0,1,0,1);
	return 0;
}
