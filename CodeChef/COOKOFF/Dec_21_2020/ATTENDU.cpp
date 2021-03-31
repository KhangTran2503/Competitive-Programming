/*	2020-12-31	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

void solve(){
	int n;
	cin >> n;
	int sum = 120;
	for (int i = 0; i < n; i++){
		char x;
		cin >> x;
		if (x == '0') sum--;
	}
	if (sum*100 >= 120*75) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}