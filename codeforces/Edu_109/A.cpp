/*	2021-05-17	*/
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
	int k;
	cin >> k;
	if (k == 100){
		cout << 1 << '\n';
		return;
	}
	int a = k;
	int b = 100 - k;
	int g = __gcd(a,b);
	a /= g;
	b /= g;
	cout << a + b << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}