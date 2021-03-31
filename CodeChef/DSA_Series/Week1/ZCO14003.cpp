#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<ll> a(n);
	for (auto &x: a) cin >> x;

	auto ans = 0LL;
	sort(a.begin(),a.end());
	for (int i = 0; i < n; i++)
	       ans = max(ans,a[i]*(ll)(n - i));
	cout << ans;	
	return 0;
}
