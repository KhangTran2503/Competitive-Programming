#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll K;
int d1, d0;
int sum_mod2[5] = {0};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
       	while (T--){
		cin >> K >> d0 >> d1;
		int mod = 0;
		if (K == 2){
			if ((d0 + d1) % 3 == 0) cout << "YES\n";
			else cout << "NO\n";
		}
		else{
			int d2 = (d0 + d1) % 10;
			sum_mod2[0] = d2;
			for (int i = 1; i <= 4; i++) sum_mod2[i] = (sum_mod2[i - 1]*2) % 10;
			
			sum_mod2[1] %= 3;
			for (int i = 2; i <= 4; i++) sum_mod2[i] = (sum_mod2[i - 1] + sum_mod2[i]) % 3;
			
			K -= 3LL;
			ll repeat = K/4LL;
			ll remain = K % 4;
			
			ll ans = (d0 + d1 + d2) % 3;
			ans = (ans + (repeat*sum_mod2[4]) % 3) % 3;
			if (remain) ans = (ans + sum_mod2[remain]) % 3;
			
			if (ans) cout << "NO\n";
			else cout << "YES\n";			
	
		}
	}	
	return 0;
}
