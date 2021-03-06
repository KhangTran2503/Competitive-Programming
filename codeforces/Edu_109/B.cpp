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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x: a) cin >> x;
	if (is_sorted(all(a))){
		cout << 0 << '\n';
		return;
	}
	if (a[0] == 1 || a[n - 1] == n){
		cout << 1 << '\n';
		return;
	}
	if (a[0] == n && a[n - 1] == 1){
		cout << 3 << '\n';
		return;
	}
	cout << 2 << '\n';
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}