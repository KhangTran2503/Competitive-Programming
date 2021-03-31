// prefix [min,max] luu doan gia tri co the cua prefix (vi cac gia tri lien tuc)
// suffix [min,max] .....

// khi xoa doan [l,r] thi gia tri doan suffix thay doi -sum[r] + sum[l - 1]
/*	2021-01-22	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int n, m;
vector<int> sum, pre_min,pre_max,suf_min,suf_max;

void solve(){
	cin >> n >> m;
	sum.assign(n + 2,0);
	pre_min.assign(n + 2,INF);
	pre_max.assign(n + 2,-INF);
	suf_min.assign(n + 2,INF);
	suf_max.assign(n + 2,-INF);
	pre_min[0] = 0;
	pre_max[0] = 0;
	for (int i = 1; i <= n; i++){
		char x;
		cin >> x;
		if (x == '+') sum[i] = sum[i - 1] + 1;
		else sum[i] = sum[i - 1] - 1; 
		pre_min[i] = min(pre_min[i - 1],sum[i]);
		pre_max[i] = max(pre_max[i - 1],sum[i]);
	}
	
	for (int i = n; i >= 1; i--){
		suf_min[i] = min(suf_min[i + 1],sum[i]);
		suf_max[i] = max(suf_max[i + 1],sum[i]);
	}
	
	while (m--){
		int l, r;
		cin >> l >> r;
		int l_out = min(pre_min[l - 1],suf_min[r + 1] - sum[r] + sum[l - 1]);
		int r_out = max(pre_max[l - 1],suf_max[r + 1] - sum[r] + sum[l - 1]);
		// consecutive => solution
		cout << r_out - l_out + 1 << '\n';
	}
	
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}

