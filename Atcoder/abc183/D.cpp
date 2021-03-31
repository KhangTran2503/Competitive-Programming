#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 2*int(1e5) + 10;
//vector<ll> used;
int n;
ll W;
vector<ll> used(Maxn);

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> W;
	used.resize(Maxn);
	for (int i = 0; i < n; i++){
		int s, t, p;
		cin >> s >> t >> p;
		used[s] += (ll)p;
		used[t] -= (ll)p;
	}
	
	ll ans = used[0];
	for (int i = 1; i < Maxn; i++){
		used[i] += used[i - 1];
		ans = max(ans,used[i]);
	}
	
	if (ans > W) cout << "No";
	else cout << "Yes";
	return 0;
}
