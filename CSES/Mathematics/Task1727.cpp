#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int n, k;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	ld ans = 0.0;
	
	for (int i = 1; i <= k; i++){
		ld f1 = 1;
		ld f2 = 1;
		for (int j = 0; j < n; j++){
			f1 *= ((ld)i/(ld)k);
			f2 *= ((ld)(i - 1.0)/(ld)k);
		}
		ans += (ld)i*(f1 - f2);
	}
	ans *= 1e6;
	ans = round(ans);
	ans *= 1e-6;
	cout << fixed << setprecision(6) << ans;
	return 0;
}
