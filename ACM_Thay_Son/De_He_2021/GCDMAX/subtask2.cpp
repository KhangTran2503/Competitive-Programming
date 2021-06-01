/*	2021-05-25	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
ll Sum;
int N, K;
vector<ll> r;
vector<ll> a;

void update(ll &ans,ll d){
	r.assign(N,0);
	for (int i = 0; i < N; i++)
		r[i] = a[i] % d;
	
	sort(all(r));
	
	ll opt = 0;
	int lef = 0, rig = N - 1;
	while (lef < rig){
		ll min_r = min(r[lef],d - r[rig]);
		opt += min_r;
		r[lef] -= min_r;
		r[rig] += min_r;
		if (r[lef] == 0) lef++;
		if (r[rig] == d) rig--;
	}
	
	for (int i = 0; i < N; i++)
		if (r[i] % d != 0){
			return;
		}
	if (opt <= K) ans = max(ans,d);
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> K;
	a.resize(N);
	Sum = 0;
	for (int i = 0; i < N; i++){
		cin >> a[i];
		Sum += (ll)a[i];
	}
	
	if (Sum*N <= 50000000){
		ll ans = 0;
		for (ll d = 1; d <= Sum; d++) update(ans,d);
		cout << ans;
	}
	else cout << -1;
	return 0;
}