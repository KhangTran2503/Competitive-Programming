#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	int ans = 0;
	int max_len = 0;
	for (int d = 2; d <= 1000; d++){
		int len = 0;
		for (int x: a)
			if (x % d == 0) len++;
		if (len > max_len){
			max_len = len;
			ans = d;
		}
	}
	cout << ans;
	return 0;
}
