//AC
/*	2021-06-20	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

void solve(int t){
	double d, u, v;
	cin >> d >> v >> u;
	if ((u <= v) || (u == 0) || (v == 0)){
		cout << "Case " << t << ": can't determine\n";
		return;
	}
	double t1 = d/u;
	double t2 = d/sqrt(u*u - v*v);
	double ans = t2 - t1;
	cout << fixed << setprecision(3) << "Case " << t << ": " << ans << '\n'; 
}



int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
	return 0;
}
