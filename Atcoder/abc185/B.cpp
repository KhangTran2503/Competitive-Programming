/*	2020-12-13	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
int n, m, t;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> t;
	//vector<int> a(m), b(m);
	int now = 0;
	int energy = n;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		energy -= (x - now);
		if (energy <= 0){
			cout << "No";
			return 0;
		}
		energy += (y - x );
		energy = min(energy,n);
		now = y;
	}
	
	energy -= (t - now);
	if (energy <= 0){
		cout << "No";
		return 0;
	}
	cout << "Yes";
	
	return 0;
}