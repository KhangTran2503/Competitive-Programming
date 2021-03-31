/*	2021-01-27	*/
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
	vector<int> b(n);
	for (int i = 0; i < n; i++){
		char x;
		cin >> x;
		b[i] = x - '0';
	}
	
	vector<int> c = {1 + b[0]};
	vector<int> a = {1};
	for (int i = 0; i < n; i++){
		for (int d = 1; d >= 0; d--)
			if ((i != 0) && (b[i] + d != c.back())) {
				c.push_back(b[i] + d);
				a.push_back(d);
				break;
			}
	}
	for (int i =0; i < n; i++) cout << a[i];
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}