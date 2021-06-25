// Digit Counting
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

void solve(){
	vector<int> cnt(10);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++){
		int u = i;
		while (u){
			cnt[u % 10]++;
			u /= 10;
		}
	}
	for (int i = 0; i < 10; i++) cout << cnt[i] << " \n"[i == 9];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}


