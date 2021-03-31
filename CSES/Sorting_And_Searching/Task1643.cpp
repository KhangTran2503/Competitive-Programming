#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	ll maxsum = a[0];
	ll sum = a[0];
	for (int i = 1; i < n; i++){
		if (sum < 0) sum = a[i];
		else sum += a[i];
		maxsum = max(maxsum,sum);
	}
	cout << maxsum;
	return 0;
}
