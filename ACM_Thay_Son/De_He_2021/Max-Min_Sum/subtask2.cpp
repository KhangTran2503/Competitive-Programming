/*	2021-05-25	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const ll INF = (ll)(1e9) + 10;
const ll Mod = (ll)(1e9) + 7;
ll C[1005][1005];
int N, K;
void init(){
	for (int i = 0; i <= 1000; i++) C[0][i] = 1;
	for (int i = 1; i <= 1000; i++)
		for (int j = 1; j <= i; j++)
			C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % Mod;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> K;
	if (N <= 1000 && K <= 1000){
		init();
		//cout << C[2][4] << '\n';
		vector<ll> a(N);
		for (int i = 0; i < N; i++) cin >> a[i];
		sort(a.begin(),a.end());
		ll ans = 0;
		for (int i = N - 1; i >= K - 1; i --){
			ll val = (a[i] - a[N - 1 - i] + Mod + Mod) % Mod;
			val = (val * C[K-1][i]) % Mod;
			ans = (ans + val) % Mod;
		}
		cout << ans;
	}
	else cout << -1;
	return 0;
}