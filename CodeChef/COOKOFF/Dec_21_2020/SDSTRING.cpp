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
string s;

void solve(){
	cin >> s;
	int n = (int)s.size();
	if (n & 1) cout << -1 << '\n';
	else {
		int one = 0;
		int zero = 0;
		for (char x: s) 
			if (x == '0') zero++;
			else one++;
		if (one > 0 && zero > 0) cout << abs(one - zero)/2 << '\n';
		else cout << -1 << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}