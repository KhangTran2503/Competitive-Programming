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

void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> sumxor(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sumxor[i] = sumxor[i - 1]^a[i];
	}
	
	//    a1^a2......^a6
	//    a1^a2^a3
	//            a4^...^a6
	
	for (int i = 1; i <= n - 1; i++)
		if (sumxor[i] == (sumxor[n]^sumxor[i])){
			cout << "YES\n";
			return;
		}
		
	for (int i = 1; i <= n - 2; i++)
		for (int j = i + 1; j <= n - 1; j++){
			int tmp1 = sumxor[i];
			int tmp2 = sumxor[j]^sumxor[i];
			int tmp3 = sumxor[n]^sumxor[j];
			if (tmp1 == tmp2 && tmp1 == tmp3){
				cout << "YES\n";
				return;
			}
		}
	cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}