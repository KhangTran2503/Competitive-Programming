/*	2020-12-07	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
vector<ll> W;
ll memo[55][55];
int n, k;
ll A, B;
vector<int> bit;

ll dp(int pos,int num,bool less){
	if (pos == n) return (num == k);
	ll res = memo[pos][num];
	if ((less) && (res != -1)) return res;
	res = 0;
	int max_d = (less) ? 1: bit[pos];
	for (int d = 0; d <= max_d; d++)
		res += dp(pos + 1,num + d,less || (d < max_d));
	if (less) memo[pos][num] = res;
	return res;
}

ll calc(ll x){
	bit.assign(n,0);
	for (int i = 0; i < n; i++)
		if (x >= W[i]){
			bit[i] = 1;
			x -= W[i];
		}
	return dp(0,0,0);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k;
	W.resize(n);
	bit.resize(n);
	for (auto &w: W) cin >> w;
	sort(rall(W));
	//for (ll w: W) cout << w << ' ';
	//cout << '\n';
	memset(memo,-1,sizeof(memo));
	cin >> A >> B;
	cout << calc(B) - calc(A - 1);
	return 0;
}