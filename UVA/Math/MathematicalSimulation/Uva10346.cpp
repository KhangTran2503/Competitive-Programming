// Peter's Smoke
/*	2021-06-21	 */
// AC
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int n, k;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	while (cin >> n >> k){
		int ans = n;
		while (n >= k){
			ans += (n/k);
			n = (n/k) + (n % k);
		}
		cout << ans << '\n';
	}
	return 0;
}
