/*	2021-06-07	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const int MaxN = int(1e6) + 5;
//vector<vector<int>> divisor(MaxN);
vector<int> prime(MaxN);
vector<ll> cnt(MaxN);
int K;
// sigma(X) la so luong uoc cua X
// X la so chinh phuong
// X' = sqrt(X)
// => Duyet cac so  1 <= X' <= 10^6



void init(){
	
	for (int i = 2; i < MaxN; i++)
		if (prime[i] == 0){
			prime[i] = i;
			for (ll j = (ll)i*i; j < MaxN; j += i)
				if (prime[j] == 0) prime[j] = i;
		}
	
	
	cnt[1] = (1 <= K);
	for (int i = 2; i < MaxN; i++){
		int u = i;
		ll num_divi = 1;
		while (u > 1){
			int alpha = 0;
			int p = prime[u];
			while (u % p == 0){
				alpha++;
				u /= p;
			}
			num_divi *= (ll)(alpha + alpha + 1);
		}
		
		cnt[i] += cnt[i - 1];
		if (num_divi <= K) cnt[i]++;
	}
	
}

ll getr(ll x){
	ll ans = sqrt(x);
	if ((ans + 1LL)*(ans + 1LL) == x) ans++;
	return cnt[ans];
}

ll getl(ll x){
	ll ans = sqrt(x);
	if (ans*ans == x) ans--;
	return cnt[ans];
}

void solve(){
	ll l, r;
	cin >> l >> r;
	cout << getr(r) - getl(l) << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> K;
	
	init();
	cin >> T;
	while (T--) solve();
	return 0;
}
