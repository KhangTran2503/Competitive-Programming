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

void solve(int t){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	sort(all(a));
	cout << "Case " << t << ": " << a[n/2] << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) solve(i + 1);
	return 0;
}
