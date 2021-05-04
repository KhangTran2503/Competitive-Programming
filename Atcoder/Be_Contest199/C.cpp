#include <bits/stdc++.h>
using namespace std;
int n, q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<vector<char>> s(2,vector<char> (n));
	for (int i = 0; i < n; i++) cin >> s[0][i];
	for (int i = 0; i < n; i++) cin >> s[1][i];

	int flip = 0;
	
	int q;
	cin >> q;
	while (q--){
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 2) flip = 1 - flip;
		else {
			l--;
			r--;
			if (l < n){
				if (r < n) swap(s[flip][l],s[flip][r]);
				else swap(s[flip][l],s[1 - flip][r - n]);
			}
			else swap(s[1 - flip][l - n],s[1 - flip][r - n]);
		}
	}
	
	for (int i = 0; i < n; i++) cout << s[flip][i];
	for (int i = 0; i < n; i++) cout << s[1 - flip][i];
	return 0;
}