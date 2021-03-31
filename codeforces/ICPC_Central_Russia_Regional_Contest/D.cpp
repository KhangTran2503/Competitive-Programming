#include <bits/stdc++.h>
#define ll long long
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
using namespace std;
const ll INF = (ll)(1e18) + 5;
const ll limit = (ll)(1e18) + 5;
int prime[] = {0,2,3,5,7,11,13,17,19,23,29};
vector<vector<ll>> pw(11);
int n;
ll memo[1005][11];
 
void init(){
	for (int i = 1; i <= 10; i++){
		pw[i].emplace_back(1);
		while (pw[i].back() < limit/prime[i])
			pw[i].emplace_back(pw[i].back()*(ll)prime[i]);
	}
}
 
ll dp(int num,int pos){
	if (num == 1) return 1LL;
	if (pos == 0) return INF;
	ll &ans = memo[num][pos];
	if (ans != -1) return ans;
	ans = dp(n,pos - 1);
	int h = pw[pos].size();
	for (int a = 1; a < h; a++)
		if (num % (a + 1) == 0){
			ll tmp = dp(num/(a + 1),pos - 1);
			if (tmp < limit/pw[pos][a]) ans = min(ans,tmp*pw[pos][a]);
		}
	return ans;
}
 
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	init();
	memset(memo,-1,sizeof(memo));
	cout << dp(n,10);
	return 0;
} 