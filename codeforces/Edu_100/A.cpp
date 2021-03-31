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
int a, b, c;

void solve(){
	cin >> a >> b >> c;
	int t = (a + b + c)/9;
	int r = (a + b + c) % 9;
	cout << (((r == 0) && (min({a,b,c}) >= t)) ? "Yes\n" : "No\n");
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}