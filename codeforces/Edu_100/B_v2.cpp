/*	2020-12-18	*/
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
vector<int> a;
/*
	Consider 2|ai - bi| <= ai.
	Assume ai >= bi => bi <= ai <= 2bi 
	=> choose bi = 2^k (k greatest such that bi <= ai)
*/
void solve(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		int l = log2(x);
		cout << (1 << l) << ' ';
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}