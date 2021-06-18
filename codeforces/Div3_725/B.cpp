/*	2021-06-10	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;


void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	
	if (sum % n != 0){
		cout << -1 << '\n';
		return;
	}
	
	sort(rall(a));
	int mean = sum/n;
	int need = 0;
	for (int i= 0; i < n; i++)
		if (a[i] < mean) need += (mean - a[i]);
	
	if (need == 0){
		cout << 0 << '\n';
		return;
	}
	
	int remain = 0;
	int ans;
	for (int i = 0; i < n; i++){
		if (a[i] > mean) remain += (a[i] - mean);
		if (remain >= need){
			ans = i + 1;
			break;
		}
	}
	cout << ans << '\n';
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}
