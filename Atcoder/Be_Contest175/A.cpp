#include <bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	
	int ans = 0;
	for (int i = 0; i < s.size(); ){
		if (s[i] == 'R'){
			int j = i;
			while (j < s.size() && s[j] == 'R') j++;
			ans = max(ans,j - i);
			i = j;	
		}
		else i++;	
	}
	cout << ans;
	return 0;
}
