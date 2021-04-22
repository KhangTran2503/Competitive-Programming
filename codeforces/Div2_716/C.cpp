/*	2021-04-20	*/
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
	set<int> s;
	ll p = 1;
	for (int i = 1; i < n; i++)
		if (__gcd(i,n) == 1) {
			s.insert(i);
			p = (p*(ll)i) % n;
		}
	if (p > 1) s.erase(p);
	cout << (int)s.size() << '\n';
	for (int x: s) cout << x << ' ';
	return 0;
}