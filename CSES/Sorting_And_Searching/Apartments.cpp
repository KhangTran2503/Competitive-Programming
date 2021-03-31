#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
using namespace std;
int n, m, k;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	vector<int> a(n);
	vector<int> b(m);
	for (int &x: a) cin >> x;
	for (int &x: b) cin >> x;
	
	sort(all(a));
	sort(all(b));

	int pos = 0;
	vector<int> visit(m,0);
	int ans = 0;
	for (int x: a){	
		while (pos < m && b[pos] < x - k) pos++;
		while (pos < m && b[pos] <= x + k && visit[pos]) pos++;
		//cout << pos << ' ';
		if (pos == m) break;
		//cout << b[pos] << ' ' << x + k << '\n';
		if (b[pos] > x + k) continue;
		ans++;	
		visit[pos++] = 1;
	}
	cout << ans;

	return 0;
}
