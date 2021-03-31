#include <bits/stdc++.h>
#define bitcount(x) __builtin_popcount(x)
#define all(s) (s).begin(),(s).end()
#define uni(s) (s).erase(unique(all(s)),s.end())
using namespace std;
vector<int> a;
map<vector<int>,int> match;
int n;
//  xi = ai^mask for all mask
//  divide two part xi, xi'
//  We have system of equations: x1 + x1' = x2 + x2'			x2 - x1 = x1' - x2'
//								 .........= ........     <=>  	------- = ........
//								 .........= ........			....... = ........		
//                               x1 + x1' = xn + xn'			xn - x1 = x1' - xn'
//  So, we need check d1 = d2

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(all(a));
	uni(a);
	n = a.size();	
	// calc x1, x2,... xn	
	int maxmask = (1 << 15);	
	for (int mask = 0; mask < maxmask; mask++){
		vector<int> d1(n);
		for (int i = 0; i < n; i++){
			int u = (a[i] >> 15);     
			d1[i] = bitcount(u ^ mask);
			if (i) d1[i] -= d1[0];
		}
		d1[0] = 0;
		match[d1] = (mask << 15);
	}	


	for (int mask = 0; mask < maxmask; mask++){
		vector<int> d2(n);
		for (int i = 0; i < n; i++){
			int u = (a[i] & (maxmask - 1));
			d2[i] = bitcount(u ^ mask);
			if (i) {
				d2[i] -= d2[0];
				d2[i] = -d2[i];
			}	
		}
		d2[0] = 0;
		if (match.count(d2)){
			cout << (match[d2] | mask);
			return 0;
		}
	}

	cout << -1;
	return 0;
}