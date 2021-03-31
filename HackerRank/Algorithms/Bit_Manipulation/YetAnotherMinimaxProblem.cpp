/*	2020-12-31	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	
	for (int LBS = 31; LBS >= 0; LBS--){
		int ans = INT_MAX;
		bool same = true;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++){
				if (((a[i] >> LBS) & 1) != ((a[j] >> LBS) & 1)){
					same = false;
					ans = min(ans,a[i]^a[j]);
				}
		}
		if (!same){
			cout << ans;
			return 0;
		}
	}
	cout << 0;
	return 0;
}