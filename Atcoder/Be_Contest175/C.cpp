#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll X, K, D;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> X >> K >> D;
	
	X = abs(X);
	ll move2zero = X/D;
	if (move2zero >= K) cout << X - K*D;
	else {
		X -= D*move2zero;
		if (abs(move2zero - K) % 2 == 1){
			ll ans = min(abs(X + D),abs(X - D));
			cout << ans;
		}
		else cout << X;
	}
	return 0;
}
