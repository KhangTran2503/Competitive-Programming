#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> s;
	if (n & 1) cout << -1;
	else {
		
		int sum = 0;
		int presum = 0;
		//int cnt = 0;
		int ans = 0;
		for (char x: s){
			presum = sum;
			if (x == '(') {
				sum++;
			}
			else {
				//if (sum == 0) ans++;
				sum--;
			}
			if (sum < 0) ans++;
			else if (sum == 0 && presum < 0) ans++;
			//cout << sum << ' ' << ans << '\n';
			//if (sum < 0) ans = ans + abs(sum) ;
		}
		if (sum == 0) cout << ans;
		else cout << -1;
	}
	return 0;
}
