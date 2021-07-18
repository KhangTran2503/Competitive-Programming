/*	2021-07-18	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

ll calc(int n){
	ll ans = (ll)n*(n + 1)/2LL;
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		ans += calc(b) - calc(a - 1);
	}
	
	cout << ans;
	return 0;
}
