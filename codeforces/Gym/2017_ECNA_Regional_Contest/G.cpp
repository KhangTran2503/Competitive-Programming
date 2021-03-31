/*	dp[i][save][rm] xet vi tri thu i da lay save cai va da xoa rm cai
/	if rm == 0 -> dp[i + 1][max(save - 1,0)][rm + 1] 
* 			   -> dp[i + 1][save + 1][rm] + min(a[i],b[save])
* 
* 	if rm == 1 -> dp[i + 1][save + 1][rm - 1] + min(a[i],b[save])
/			   -> dp[i + 1][0][0]
/
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef ll INF = (ll)(1e18);
int n, m;
vector<vector<vector<ll>>> f;
vector<int> a, b;

ll dp(int i,int save,int rm){
	if (i == n) return 0;
	if (f[i][save][rm] != -1) return f[i][save][rm];
	ll ans = 0;
	if (rm == 0){
		ans = dp(i + 1,max(save - 1,0),rm + 1);
		ans = max(ans,dp(i + 1,save + 1,rm) + min(a[i],b[save]));
	}
	else {
		ans = dp(i + 1,save + 1,rm - 1) + min(a[i],b[save]);
		ans = max(ans, dp(i + 1,0,0));
	}
	return f[i][save][rm] = ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	a.resize(n);
	b.resize(n);
	
	for (int &ai: a) cin >> ai;
	
	b[0] = m;
	for (int i = 1; i < n; i++) b[i] = (b[i - 1]*2)/3;
	
	f.assign(n + 1,vector<vector<ll>> (n + 1,vector<ll> (2,-1)));
	cout << dp(0,0,0); 
	return 0;
}
