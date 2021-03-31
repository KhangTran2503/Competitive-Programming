/*	2021-01-11	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int &x: a) cin >> x;
	for (int &x: b) cin >> x;
	ll sum = 0;
	for (int i = 0; i < n; i++) sum += (ll)a[i]*b[i];
	cout << ((sum == 0) ? "Yes" : "No");
	return 0;
}