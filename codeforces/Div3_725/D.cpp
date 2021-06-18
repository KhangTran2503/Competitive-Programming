/*	2021-06-10	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const int MaxN = (int)(1e5) + 5;
int a, b, k;
vector<int> prime;
vector<bool> is_prime;

void init(){
	is_prime.assign(MaxN,false);
	for (int i = 2; i < MaxN; i++)
		if (!is_prime[i]){
			prime.push_back(i);
			if (i <= 1000)
				for (int j = i*i; j < MaxN; j += i) is_prime[j] = 1;
		}
}

int num_prime(int u){
	int cnt = 0;
	for (int x: prime){
		if (u < x) break;
		while (u % x == 0){
			cnt++;
			u /= x;
		}
	}
	if (u > 1) cnt++;
	return cnt;
}

void solve(){
	cin >> a >> b >> k;
	
	int max_step = num_prime(a) + num_prime(b);
	
	if (k > max_step){
		cout << "NO\n";
		return;
	}
	
	if (a == b){
		if (k == 1) cout << "NO\n";
		else cout << "YES\n";
		
		return;
	}
	
	if (__gcd(a,b) == a || __gcd(a,b) == b){
		cout << "YES\n";
		return;
	}
	
	if (k >= 2){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T = 1;
	init();
	cin >> T;
	while (T--) solve();
	return 0;
}
