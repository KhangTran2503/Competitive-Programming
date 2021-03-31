/*	2021-01-21	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const ll INF = 2*(ll)(1e18) + 10;
ll X, Y;
// Y -> X : 
// operator: X/2,X - 1,X + 1
map<ll,ll> save;

ll f(ll u){
	if (u <= X) return abs(X - u);
	auto it = save.find(u);
	if (it != save.end()) return it->second;
	ll ans = INF;
	if (u & 1) ans = min({ans,abs(u - X),2 + f((u + 1)/2),2 + f((u - 1)/2)});
	else ans = min({ans,abs(u - X),1 + f(u/2)});
	save[u] = ans;
	return ans; 
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> X >> Y;
	cout << f(Y);
	return 0;
}