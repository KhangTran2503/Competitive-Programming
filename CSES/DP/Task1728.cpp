/*	2020-12-18	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<int> a(n);
	for (auto &x: a) cin >> x;
	
	ld ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++){
			int inv = 0;
			if (a[i] > a[j]) inv = (a[j])*(a[j] - 1)/2 + (a[i] - a[j])*a[j];
			else inv = (a[i])*(a[i] - 1)/2;
			ans += (ld)inv/(ld)(a[i]*a[j]);
		}
	
	cout << fixed << setprecision(6) << ans;
	return 0;
}