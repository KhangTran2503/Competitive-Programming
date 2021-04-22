/*	2021-04-06	*/
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
	int T;
	cin >> T;
	while (T--){
		ll n;
		cin >> n;
		int cnt2 = 0;
		while (n % 2 == 0){
			cnt2++;
			n/=2LL;
		}
		if (cnt2 == 0) cout << "Odd\n";
		if (cnt2 == 1) cout << "Same\n";
		if (cnt2 > 1) cout << "Even\n"; 
	}
	return 0;
}