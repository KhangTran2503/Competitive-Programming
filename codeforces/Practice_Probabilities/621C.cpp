/*	2021-07-02	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int n, p;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> p;
	
	double prob = 0;
	vector<ii> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	
	for (int i = 0; i < n; i++){
		int j = (i + 1) % n;
		int len1 = a[i].second - a[i].first + 1;
		int len2 = a[j].second - a[j].first + 1;
		int num1 = (a[i].second/p) - (a[i].first - 1)/p;
		int num2 = (a[j].second/p) - (a[j].first - 1)/p;
		prob += (1 - ((double)(len1 - num1)/(double)(len1))*((double)(len2 - num2)/(double)(len2)));
	}
	
	double E = prob*1000*2;
	cout << fixed << setprecision(8) << E;
	return 0;
}
