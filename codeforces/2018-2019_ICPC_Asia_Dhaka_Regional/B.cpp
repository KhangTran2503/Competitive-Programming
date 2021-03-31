/*	2020-12-03	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef array<int,10> arr10;
const int INF = (int)(1e9);
vector<int> digit;
map<ll,ll> memo[15][2];
ll pw14[10];
ll memo_cnt[15][2];
ll L, R;


ll figure(int pos,bool low){
	if (pos == -1) return 1;
	ll &res = memo_cnt[pos][low];
	if (res != -1) return res;
	res = 0;
	int max_d = (low) ? 9: digit[pos];
	for (int d = 0; d <= max_d; d++)
		res += figure(pos - 1,low || (d < max_d));
	return res;
}

ll dp(int pos,bool low,bool lead,ll Hash){
	if (pos == -1) return 0;
	auto it = memo[pos][lead].find(Hash);
	if ((low) && (it != memo[pos][lead].end())) return memo[pos][lead][Hash];
	ll res = 0;
	int max_d = (low) ? 9 : digit[pos];
	
	ll inv = 0;
	ll H = Hash;
	for (int d = 0; d <= max_d; d++){
		bool nlow = (low || (d < max_d));
		res += inv*figure(pos - 1,nlow);
		
		bool nlead = (lead || (d > 0));
		res += dp(pos - 1,nlow,nlead,(nlead) ? Hash + pw14[d] : Hash);
		inv += (H % 14LL);
		H /= 14LL;
	}
	//cout << res << '\n';
	if (low) memo[pos][lead][Hash] = res;
	return res;
}


ll calc(ll x){
	digit.clear();
	//reset();
	while (x){
		digit.push_back(x % 10);
		x /= 10;
	}
	

	memset(memo_cnt,-1,sizeof(memo_cnt));
	figure((int)digit.size() - 1,0);
	return dp((int)digit.size() - 1,0,0,0);
}


void solve(int t){
	cin >> L >> R;
	
	ll ans1 = calc(R);
	L--;
	ll ans2 = (L > 0) ? calc(L) : 0;
	
	cout << "Case " << t << ": " << ans1 - ans2 << '\n';
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	pw14[0] = 1;
	for (int i = 1; i < 10; i++) pw14[i] = pw14[i - 1]*14LL;
	for (int i = 1; i <= T; i++) solve(i);
	return 0;
}