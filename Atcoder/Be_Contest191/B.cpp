/*	2021-02-12	*/
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
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		if (a != x) cout << a << ' ';
	}
	return 0;
}