/*	2021-05-30	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int n, m;
string s;

void solve(){
	vector<int> a(n);
	cin >> n >> m;
	cin >> s;
	int t = min(n,m);
	while (t--){
		string x(n,'0');
		for (int i = 0; i < n; i++){
			x[i] = s[i];
			if (s[i] == '0'){
				int neigh = 0;
				if (i > 0 && s[i - 1] == '1') neigh++;
				if (i + 1 < n && s[i + 1] == '1') neigh++;
				if (neigh == 1) x[i] = '1';
			}
		}
		s = x;
	}
	cout << s << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}