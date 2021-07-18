/*	2021-07-18	 */
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

// ak*(p + 0.5) = ak' * (2p + 1)


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	vector<int> a(n);
	
	ll LCM = 1;
	for (int i = 0; i < n; i++){
		 cin >> a[i];
		 a[i] >>= 1;
	}
	
	for (int i = 0; i < n; i++){
		LCM = (LCM/__gcd(LCM,(ll)a[i]))*(ll)a[i];
		if (LCM > m){
			cout << 0;
			return 0;
		}
	}
	
	// check 2p + 1 
	for (int i = 0; i < n; i++){
		ll q = LCM/a[i];
		if (q % 2 == 0){
			cout << 0;
			return 0;
		}
	}	
	
	int range = m/LCM;
	cout << range/2 + (range % 2);
	
	return 0;
}
