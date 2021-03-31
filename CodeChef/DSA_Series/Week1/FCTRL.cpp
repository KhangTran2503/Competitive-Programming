#include <bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--){
		int n;
		cin >> n;
		int ans = 0;
		while (n){
			n /= 5;
			ans += n;
		}
		cout << ans << '\n';
	}
	return 0;
}
