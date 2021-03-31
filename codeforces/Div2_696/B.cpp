/*	2021-01-28	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const int Maxn = 3*int(1e5);
vector<bool> is_prime(Maxn);

void Era(){
	is_prime.assign(Maxn,true);
	is_prime[1] = false;
	for (int i = 2; i < Maxn; i++)
		if (is_prime[i]){
			if (i < 548)
				for (int j = i*i; j < Maxn; j += i) is_prime[j] = false;
		}
}



void solve(){
	int d;
	cin >> d;
	int num = 1;
	ll ans = 1;
	for (int i = 0; i < 2; i++){
		num += d;
		while (!is_prime[num]) num++;
		ans *= (ll)num;
	}
	cout << ans << '\n';
	
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	Era();
	while (t--) solve();
	return 0;
}