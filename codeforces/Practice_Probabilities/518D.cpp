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
vector<vector<double>> prob;
int n, t;
double p;

// prob[i,j] is prob when i people standing on the escalator   and j time
int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> p >> t;
	
	prob.resize(n + 2,vector<double> (t + 2));
	
	prob[0][0] = 1;
	//for (int i = 0; i <= t; i++) prob[0][i + 1] = prob[0][i]*(1 - p);
	
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= t; j++){
			if (i == n) prob[i][j + 1] += prob[i][j];
			else{
				prob[i + 1][j + 1] += p*prob[i][j];
				prob[i][j + 1] += (1 - p)*prob[i][j];
			}
			//cout << prob[i][j] << ' ';
		}
		//cout << '\n';
	}
	
			
	double E = 0;
	for (int i = 1; i <= n; i++) E += i*prob[i][t];
	
	cout << fixed << setprecision(8) << E;
	return 0;
}
