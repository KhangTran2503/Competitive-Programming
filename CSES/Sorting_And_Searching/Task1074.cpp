#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> p(n);
	for (int &x: p) cin >> x;
	sort(p.begin(),p.end());
	
	ll ans = 0;
	for (int x: p) ans += (ll)abs(x - p[n/2]);
	cout << ans;
	return 0;
}
