#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<vector<ll>> matrix;
const int INF = (int)(1e9);
const ll Mod = (ll)(1e9) + 7;
vector<vector<ll>> base = {{2,0,4,0},{0,2,4,1},{0,1,0,0},{0,0,0,2}};
matrix I = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

matrix operator *(matrix a,matrix b){
	int n = a.size();
	int m = a[0].size();
	int _m = b.size();
	int p = b[0].size();
	assert(m == _m);
	matrix c(n,vector<ll> (p,0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < p ; j++)
			for (int k = 0; k < m; k++)
				c[i][j] = (c[i][j] + a[i][k]*b[k][j] % Mod) % Mod;
	return c;
}

matrix fast_pow(int y){
	matrix ans = I;
	while (y){
		if (y & 1) ans = ans*base;
		base = base*base;
		y >>= 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	ll n;
	cin >> n;
	if (n == 1) cout << 2;
	else {
		matrix f0 = {{0},{6},{1},{4}};
		matrix ans = fast_pow(n - 2)*f0;
		ll res = ((ans[0][0] + ans[1][0]) << 2) % Mod;
		cout << res;
	}
	return 0;
}