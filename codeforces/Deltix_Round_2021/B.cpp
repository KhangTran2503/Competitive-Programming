/*	2021-05-31	*/
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
	vector<int> a(n);
	for (int &x: a) cin >> x;
	cout << 3*n << '\n';
	for (int i = 0; i < n; i += 2){
		cout << 1 << ' ' << i + 1 << ' ' << i + 2 << '\n';
		cout << 2 << ' ' << i + 1 << ' ' << i + 2 << '\n';
		cout << 1 << ' ' << i + 1 << ' ' << i + 2 << '\n';
		cout << 1 << ' ' << i + 1 << ' ' << i + 2 << '\n';
		cout << 2 << ' ' << i + 1 << ' ' << i + 2 << '\n';
		cout << 1 << ' ' << i + 1 << ' ' << i + 2 << '\n'; 
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}