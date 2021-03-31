/*	2020-12-11	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);

void solve(){
	int m;
	cin >> m;
	int sumxor = 0;
	for (int i = 1; i <= m; i++) sumxor ^= i;
	if (sumxor == m) {
		cout << m << '\n';
		for (int i = 1; i <= m; i++) cout << i << ' ';
	}
	else {
		cout << m - 1 << '\n';
		for (int i = m; i >= 1; i--)
			if ((sumxor^i) == m){
				for (int j = 1; j < i; j++) cout << j << ' ';
				for (int j = i + 1; j <= m; j++) cout << j << ' ';
				break;
			}
	}
	
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}