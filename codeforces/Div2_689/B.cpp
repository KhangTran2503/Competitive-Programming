/*	2020-12-15	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9)+10;
vector<vector<char>> a;
vector<vector<int>> prefix;
int n, m;

bool check(int x,int y,int len){
	if (x + len - 1 > n) return false;
	if (y - len + 1 < 1) return false;
	if (y + len - 1 > m) return false;
	if (prefix[x + len - 1][y + len - 1] - prefix[x + len - 1][y - len] < len + len - 1) return false;
	return true;
}

void solve(){
	cin >> n >> m;
	a.assign(n + 1,vector<char> (m + 1,'.'));
	prefix.assign(n + 1,vector<int> (m + 1,0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
		
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			prefix[i][j] = prefix[i][j - 1];
			if (a[i][j] == '*') prefix[i][j]++;
		}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			int len = 1;
			while (check(i,j,len)) len++;
			ans += (len - 1);
		}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}