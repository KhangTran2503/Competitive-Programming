#include <bits/stdc++.h>
using namespace std;
int n, k;
string s, t;

string change(string x){
	if (k == 1) return "";
	stack<pair<char,int>> st;
	for (char c: x){
		if (!st.empty() && st.top().first == c){
			st.top().second++;
			if (st.top().second == k) st.pop();
		}
		else {
			st.push({c,1});
		}
	}
	
	string ans = "";
	while (!st.empty()){
		for (int i = 0; i < st.top().second; i++) ans += st.top().first;
		st.pop();
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	cin >> s;
	cin >> t;
	
	if (change(s) == change(t)) cout << "Yes";
	else cout << "No";
	return 0;
}