/*	2021-01-15	*/
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
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int greater = 0;
	for (int x: a)
		if (x > d) greater = 1;
	int can = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) 
			if (a[i] + a[j] <= d) can = 1;
	
	if (can >= greater) cout << "YES\n";
	else cout << "NO\n";
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}