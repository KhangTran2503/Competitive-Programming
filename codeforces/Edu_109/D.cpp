/*	2021-05-21	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
vector<vector<int>> dp;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<int> a(1);
	vector<int> b(1);
	
	//return 0;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (x) a.push_back(i + 1);
		else b.push_back(i + 1);
	}
	
	int _n = a.size() - 1;
	int _m = b.size() - 1;
	if (_n == 0) cout << 0;
	else {
		dp.assign(_n + 1,vector<int> (_m + 1,INF));
		for (int j = 0; j <= _m; j++) dp[0][j] = 0;
		for (int i = 1; i <= _n; i++)
			for (int j = i; j <= _m; j++){
				int tmp = min(dp[i][j - 1],dp[i - 1][j - 1] + abs(a[i] - b[j]));
				dp[i][j] = min(dp[i][j],tmp);
			}
		cout << dp[_n][_m];
	}
	return 0;
}