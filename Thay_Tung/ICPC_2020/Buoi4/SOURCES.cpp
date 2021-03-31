#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	
	ll ans = 0;
	for (int x = a; x <= b; x++){
		string y = to_string(x);
		sort(y.begin(),y.end());
		ans += (ll)stoi(y,nullptr);
	}
	cout << ans;
	return 0;
}
