/*	2021-04-20	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

bool is_square(int x){
	int sqrt_x = sqrt(x);
	while (sqrt_x*sqrt_x < x) sqrt_x++;
	return (sqrt_x*sqrt_x == x);
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	for (int x: a){
		if (!is_square(x)){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}