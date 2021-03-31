/*	2020-12-08	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
const ld EPS = 1e-9;
ll a, b;

ld f(ll x){
	return (ld)x*log(a) - (ld)b*log(x);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> a >> b;
	ll ans = 0;
	for (int i = 0; i <= 640000; i++){
		if (fabs(f(i)) < EPS){
			ans = i;
			break;
		}
	}
	cout << ans;
	return 0;
}