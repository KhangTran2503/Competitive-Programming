#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	stack<int> st;
	st.push(0);

	vector<int> ans(n + 1);
	for (int i = 1; i <= n; i++){
		while (!st.empty() && a[st.top()] >= a[i]) st.pop();
		ans[i] = st.top();
		st.push(i);
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}
