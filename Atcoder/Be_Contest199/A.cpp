#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int A, B, C;
	cin >> A >> B >> C;
	if (A*A + B*B < C*C) cout << "Yes";
	else cout << "No";
	return 0;
}