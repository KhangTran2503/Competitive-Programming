#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)(1e18);
int N;
ll K;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	
	vector<ll>  P(N + 1), C(N + 1);
	for (int i = 1; i <= N; i++) cin >> P[i];
	for (int i = 1; i <= N; i++) cin >> C[i];

	ll ans = -INF;

	vector<vector<ll>> Sum(N + 1);
	for (int i = 1; i <= N; i++){
		int root = i;
		ll sum = 0;
		do{
			root = P[root];
			sum += C[root];
			Sum[i].emplace_back(sum);
		}while (root != i);
		
		int size_cycle = Sum[i].size();

		ll val = (K/size_cycle)*Sum[i].back();
		ll remain = K % size_cycle;
		if (remain) val += Sum[i][remain - 1];
		
		ans = max(ans,val);	
	}	
	cout << ans;
	return 0;
}
