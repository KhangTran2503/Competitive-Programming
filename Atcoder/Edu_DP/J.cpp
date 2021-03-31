/*	2020-12-13	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);

/* E(x1,x2,x3) is expected value 
 * 
 * 
 */
double E[305][305][305]; 
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<int> cnt(4);
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}
	
	
	for (int x3 = 0; x3 <= n; x3++)
		for (int x2 = 0; x2 <= n; x2++)
			for (int x1 = 0; x1 <= n; x1++){
				if ((x1 == 0) && (x2 == 0) && (x3 == 0)) continue;
				if (x1 + x2 + x3 > n) continue;
				double k = x1 + x2 + x3;
				E[x3][x2][x1] = (double)n/k;
				double p1 = (double)x1/(double)(x1 + x2 + x3);
				double p2 = (double)x2/(double)(x1 + x2 + x3);
				double p3 = (double)x3/(double)(x1 + x2 + x3);
				if (x1) E[x3][x2][x1] += p1*E[x3][x2][x1 - 1];
				if (x2) E[x3][x2][x1] += p2*E[x3][x2 - 1][x1 + 1];
				if (x3) E[x3][x2][x1] += p3*E[x3 - 1][x2 + 1][x1];
			}
	
	cout << fixed << setprecision(10) << E[cnt[3]][cnt[2]][cnt[1]];
	return 0;
}