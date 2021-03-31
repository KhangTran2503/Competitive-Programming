#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		string ans = "";
		for (int i = 0; i < n; i++) ans.push_back(s[2*i]);
		cout << ans << '\n';
		
	}
	return 0;
}
