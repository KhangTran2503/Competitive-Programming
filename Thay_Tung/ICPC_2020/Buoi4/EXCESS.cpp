#include <bits/stdc++.h>
using namespace std;
string s;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	int l = 0, r = (int)(s.size()) - 1;
	int pos = -1;
	while (l <= r){
		bool ok = false;
		if (s[l] == s[r]){
			l++; r--;
			ok = true;
		}
		else if (s[l] == s[r - 1]){
			if (pos == -1) pos = r + 1;
			else{
				cout << -1;
				return 0;
			}
			r--;
			ok = true;
		}
		else if (s[l + 1] == s[r]){
			if (pos == -1){
				pos = l + 1;
			}
			else{
				cout << -1;
				return 0;
			}
			l++;
			ok = true;
		}
		else ok = false;
		if (!ok) {
			cout << -1;
			return 0;
		}
	}
	cout << pos;
	return 0;
}
