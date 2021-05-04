#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
using namespace std;
int n;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	std::vector<int> a(n);
	std::vector<int> b(n);
	for (int &x: a) cin >> x;
	for (int &x: b) cin >> x;

	int lo = *max_element(all(a));
	int hi = *min_element(all(b));
	cout << max(hi - lo + 1,0); 
	return 0;
}