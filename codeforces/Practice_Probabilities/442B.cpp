/*	2021-07-04	 */
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
	vector<ld> p(n);
	for (ld &x: p) cin >> x;
	
	sort(rall(p));
	if (p[0] == 1.0) cout << fixed << setprecision(10) << 1;
	else {
		ld P = 1;
		ld S = 0;
		for (int i = 0; i < n; i++){
			S = S + p[i]/(1 - p[i]);
			P *=(1 - p[i]);
			if (S > 1) break;
		}
		cout << fixed << setprecision(10) << S*P;
	}
	return 0;
}
