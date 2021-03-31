/*	2020-12-13	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
const int maxn = 200;
ll C[maxn + 1][maxn + 1];
void init(){
	C[0][0] = 1LL;
	for (int n = 1; n <= maxn; ++n) {
		C[n][0] = C[n][n] = 1LL;
		for (int k = 1; k < n; ++k)
			C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int L;
	cin >> L;
	init();
	cout << C[L - 1][11];
	return 0;
}