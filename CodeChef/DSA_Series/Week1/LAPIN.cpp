#include <bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	vector<int> p1(26,0), p2(26,0);
	while (T--){
		string s;
		cin >> s;
		p1.assign(26,0);
		p2.assign(26,0);
		int n = s.size();
		for (int i = 0; i < n/2; i++)
			if (i != n - i - 1){
				p1[s[i] - 'a']++;
				p2[s[n - i - 1] - 'a']++;	
			}	
		bool ok = true;
		for (int i = 0; i < 26; i++)
			ok &= (p1[i] == p2[i]);
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
