/*	2021-04-22	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const int MaxN = (int)(1e5) + 10;

/* ideal:  all elements in [l,r] are coprime 
 */

vector<int> prime(MaxN); 
vector<int> last;
vector<int> a;
vector<vector<int>> jump;
int n, q;
 
void Era(){
	for (int i = 2; i < MaxN; i++)
		if (!prime[i])
			for (int j = i; j < MaxN; j += i)
				if (!prime[j]) prime[j] = i;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	a.resize(n + 1);
	last.assign(MaxN,n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	Era();
	jump.assign(20,vector<int> (n + 2,n + 1));
	for (int i = n; i >= 1; i--){
		jump[0][i] = jump[0][i + 1];
		int u = a[i];
		while (u > 1){
			int p = prime[u];
			jump[0][i] = min(jump[0][i],last[p]);
			last[p] = i;
			while (u % p == 0) u /= p;
			//cerr << u << '\n';
		}
	}
	
	for (int k = 1; k < 20; k++)
		for (int i = 1; i <= n; i++)
			jump[k][i] = jump[k - 1][jump[k - 1][i]];
			
	while (q--){
		int l, r;
		cin >> l >> r;
		int ans = 0;
		for (int k = 19; k >= 0; k--)
			if (jump[k][l] <= r){
				ans |= (1 << k);
				l = jump[k][l];
			}
		// jump n lan => co n + 1 mang con
		cout << ans + 1 << '\n';
	}
	return 0;
}