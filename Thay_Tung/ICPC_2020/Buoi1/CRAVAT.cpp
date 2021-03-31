#include <bits/stdc++.h>
#define all(s) (s).begin(), (s).end()
using namespace std;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<pair<int,int>> a(n + 1);
	vector<int> b(n);
	
	for (int i = 0; i < n + 1; i++){
		int x;
		cin >> x;
		a[i] = {x,i};
	} 
	
	for (int &x: b) cin >> x;
	
	sort(all(a));
	sort(all(b));
	
	vector<int> prefix(n);
	vector<int> suffix(n + 1);
	
	prefix[0] = max(a[0].first - b[0],0);
	for (int i = 1; i < n; i++) prefix[i] = max(prefix[i - 1],max(a[i].first - b[i],0));
	
	suffix[n] = max(a[n].first - b[n - 1],0); 
	for (int i = n - 1; i >= 1; i--) suffix[i] = max(suffix[i + 1],max(a[i].first - b[i - 1],0));
	
	vector<int> res(n + 1);
	res[a[0].second] = suffix[1];
	res[a[n].second] = prefix[n - 1];
	for (int i = 1; i < n; i++) res[a[i].second] = max(prefix[i],suffix[i + 1]);
	
	for (int x: res) cout << x << ' ';
	return 0;
}
