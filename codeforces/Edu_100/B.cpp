/*	2020-12-18	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int n;
vector<int> a;

void solve(){
	cin >> n;
	a.assign(n,0);
	ll sum = 0;
	ll c_sum = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += (ll)a[i];
		if (i & 1) c_sum += (ll)a[i];
	}
	
	int flag = (2*c_sum >= sum);
	for (int i = 0; i < n; i++)
		if ((i + flag) & 1) cout << 1 << ' ';
		else cout << a[i] << ' ';
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}