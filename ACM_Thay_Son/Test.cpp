#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
const int Maxn = int(1e5) + 5;
const ll Mod = (ll)(1e9) + 7;
const int oo = int(1e9);
const long double esp = 1e-3;
typedef pair<int,int> ii;
long double ans = 0;
int n, m;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		ans += log2(x);	
	}	
	for (int i = 0; i < m; i++){
		int x;
		cin >> x;
		ans -= log2(x);	
	}	
	ans += esp;
	ll res  = round(pow(2,ans));
	cout << res;
	return 0;
}
