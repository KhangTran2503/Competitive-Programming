/*	2020-12-03	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
const ll MOD = (ll)(1e7) + 7;
const int Maxn = int(1e6) + 5;
ll inv2 = (MOD + 1) >> 1;
vector<int> prime;
int n;

void init(){
	vector<bool> is_prime(Maxn,false);
	for (int i = 2; i < Maxn; i++)
		if (!is_prime[i]){
			prime.push_back(i);
			if (i <= 1000) for (int j = i*i; j < Maxn; j += i) is_prime[j] = true;
		}
}


void solve(){
	ll ans = 1;
	for (int i = 0; i < (int)prime.size(); i++){
		if (prime[i] > n) break;
		ll cnt = 0;
		ll u = n;
		while (u){
			cnt += (ll)(u/prime[i]);
			u /= prime[i];
		}
		cnt = ((((cnt + 2)*(cnt + 1)) % MOD)*inv2) % MOD;
		ans = (ans*cnt) % MOD; 
	}
	cout << ans << '\n';

	//eturn true;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	init();
	while (1){
		cin >> n;
		if (n == 0) break;
		solve();
	}
	return 0;
}