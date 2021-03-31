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
	int x, y, K , N;
	cin >> x >> y >> K >> N;
	if (abs(x - y) % (2*K) == 0) cout << "Yes\n";
	else cout << "No\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}