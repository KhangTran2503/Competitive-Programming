#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int sum = 0;
		int cnt = 0;
		while (sum < n){
			cnt++;
			sum += cnt;
		}
		if (sum == n + 1) cnt++;
		cout << cnt << '\n';
	}
	return 0;
}