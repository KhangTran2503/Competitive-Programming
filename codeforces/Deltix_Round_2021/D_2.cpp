/*	2021-05-31	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
// Random 1 - (1/2)^{n}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, p;
int max_nbit = 0;
ll ans_mask;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n  >> m >> p;
	
	vector<ll> a(n,0);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			char x;
			cin >> x;
			if (x == '1') a[i] |= (1LL << j);
		}
	} 
	
	vector<int> per(n,0);
	iota(all(per),0);
	shuffle(all(per),rng);
	//for (int x: per) cout << x << ' ';
	//cout << '\n';
	
	int idx = 0;
	while (1){
		if (idx >= min(100,n)) break;
		ll cur_mask = a[per[idx]];
		//cout << per[idx] << '\n';
		
		vector<int> bit;
		for (int j = 0; j < m; j++) 
			if ((cur_mask >> j) & 1) bit.push_back(j);
		
		int n_bit = (int)bit.size();
		vector<int> cnt(1 << n_bit,0);
		
		
		
		for (int i = 0; i < n; i++){
			int mask = 0;
			for (int j = 0; j < n_bit; j++)
				if ((a[i] >> bit[j]) & 1) mask |= (1 << j);
			
			cnt[mask]++;
		}
		
		
		// iterator all submask
		int max_mask = (1 << n_bit);
		for (int msk = 0; msk < max_mask; msk++){
				int s = msk;
				while (1){
					if (s == 0) break;
					s = ((s - 1) & msk);
					cnt[s] += cnt[msk];
				}
			}
		
		
		
		for (int msk = 1; msk < max_mask; msk++)
			if (2*cnt[msk] >= n && __builtin_popcount(msk) > max_nbit){
				max_nbit = __builtin_popcount(msk);
				ll u = 0;
				for (int j = 0; j < n_bit; j++)
					if ((msk >> j) & 1) u |= (1LL << bit[j]);
				ans_mask = u; 
			}
			
		idx++;
	}
	
	for (int j = 0; j < m; j++)
		if (ans_mask & (1LL << j)) cout << '1';
		else cout << '0';
	
	return 0;
}