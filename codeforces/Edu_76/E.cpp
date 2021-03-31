#include <bits/stdc++.h>
#define all(s) (s).begin(), (s).end()
using namespace std;
int k1, k2, k3;
// LIS 

int LIS(const vector<int> & A){
	vector<int> lis;
	for (int x : A){
		if (lis.empty()) {
			lis.push_back(x);
			continue;
		}
		auto it = lower_bound(all(lis),x);
		if (it == lis.end()) lis.push_back(x);
		else *it = x;
	}
	return int(lis.size());
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k1 >> k2 >> k3;
	vector<int> a(k1);
	vector<int> b(k2);
	vector<int> c(k3);
	for (int &i: a) cin >> i;
	for (int &i: b) cin >> i;
	for (int &i: c) cin >> i;
	sort(all(a));
	sort(all(b));
	sort(all(c));

	vector<int> ans;
	for (int x: a) ans.push_back(x);
	for (int x: b) ans.push_back(x);
	for (int x: c) ans.push_back(x);

	cout << (k1 + k2 + k3) - LIS(ans);	
	return 0;
}