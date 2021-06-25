// AC
/*	2021-06-21	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int t = 0;

bool solve(){
	int N, R;
	cin >> R >> N;
	if (N == 0 && R == 0) return false;
	t++;
	
	// N(x + 1) >= R  => (x + 1) >= ceil(R/N)
	int x = R/N + (R % N != 0) - 1;
	if (x > 26) cout << "Case " << t << ": impossible\n";
	else cout << "Case " << t << ": " << x << '\n';  
	
	
	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	while (solve());
	return 0;
}
