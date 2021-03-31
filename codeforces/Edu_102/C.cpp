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
	// p = 1,2,..,k - (n - k) - 1, k, k - 1,..., k - (n - k)
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		if (i < k - (n - k)) cout << i << ' ';
		else cout << (3*k - n) - i << ' '; 
	cout << '\n';
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}