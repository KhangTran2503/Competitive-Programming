/*	2020-12-13	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
int memo[2005][2005];
int a[2005];
int b[2005];
int n, m;
int dp(int i,int j){
	if (i == 0 && j == 0) return 0;
	if (i == 0 || j == 0) return 0;
	int &res = memo[i][j];
	if (res != -1) return res;
	res = 0;
	res = max(res,dp(i - 1,j - 1) + (int)(a[i] == b[j]) + 1);
	res = max(res,max(dp(i - 1,j),dp(i,j - 1)));
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	
	memset(memo,-1,sizeof(memo));
	cout << (n + m) - dp(n,m);
	return 0;
}