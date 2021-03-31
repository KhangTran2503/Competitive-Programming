/*	2021-01-26	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const int Maxn = (int)(1e6) + 5;
ll f[Maxn] = {0};
int cnt[Maxn] = {0};
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}
	
	// dp[i] is number pair (i -> Maxn) such that gcd = i
	for (int i = Maxn - 1; i >= 1; i--){
		ll num = 0;
		for (int j = i; j < Maxn; j += i){
			num += (ll)cnt[j];
			f[i] -= f[j];
		}
		//cout << i << ' ' << num << '\n';
		f[i] += (ll)(num)*(num - 1)/2;
	}
	cout << f[1];
	return 0;
}