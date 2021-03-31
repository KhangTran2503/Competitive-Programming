#include <bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		string s;
		cin >> s;
		int x;
		cin >> x;
		
		int n = s.size();
		string w(s.size(),'1');
		
		for (int i = 0; i < n; i++) 
			if (s[i] == '0'){
				if (i >= x) w[i - x] = '0';
				if (i + x < n) w[i + x] = '0';
			}
		
		auto check = [=](const string& w){
			string ans(w.size(),'0');
			for (int i = 0; i < ans.size(); i++){
				if (i >= x && w[i - x] == '1') ans[i] = '1';
				if (i + x < n && w[i + x] == '1') ans[i] = '1';
			}
			return ans;
		};
		if (check(w) == s) cout << w << '\n';
		else cout << "-1\n";
	}
	return 0;
}
