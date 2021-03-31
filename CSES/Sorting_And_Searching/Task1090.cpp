#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
using namespace std;
int n, x;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> x;
	vector<int> p(n);
	for (int &x: p) cin >> x;
	
	sort(all(p));
	int ans = n;
	int last = n - 1;
	for (int i = 0; i < last; i++){
		while (last > i && p[i] + p[last] > x) last--;
		if (last <= i) break;
		ans--;
		last--;
	}
	cout << ans;
	return 0;
}
