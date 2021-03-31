/*	2021-01-01	*/
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
	ll n;
	cin >> n;
	if (n & 1){
		int one = 0;
		for (int i = 1; i < 64; i++)
			if ((n >> i) & 1) one++;
		if (one == 0) cout << "Louise\n";
		else {
			if (one & 1) cout << "Louise\n";
			else cout << "Richard\n";
		}
	}
	else {
		int MBS = __builtin_ctzll(n);
		int one = 0;
		for (int i = MBS + 1; i < 64; i++)
			if ((n >> i) & 1) one++;
		if ( (one + MBS) % 2 == 0) cout << "Richard\n";
		else cout << "Louise\n";
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}