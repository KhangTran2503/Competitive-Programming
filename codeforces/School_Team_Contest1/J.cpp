#include <bits/stdc++.h>
using namespace std;
string s, t;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	cin >> t;

	// size t = size s - 1
	int ans = 0;
	int l = 0;
	int r = s.size() - 1;

	while (l < t.size() && s[l] == t[l]) l++;
	while (r > 0 && s[r] == t[r - 1]) r--;
	//cout << l << ' ' << r << '\n';
	if (r <= l) {
		cout <<  l - r  + 1 << '\n';
		for (int i = r; i <= l; i++) cout << i + 1 << ' '; 
	}
	else cout << 0;
	return 0;
}