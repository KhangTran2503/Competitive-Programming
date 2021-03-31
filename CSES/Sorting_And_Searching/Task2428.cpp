/*	2021-01-25	*/
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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	map<int,int> s;
	int j = 0;
	ll cnt = 0;
	for (int i = 0; i < n; i++){
		if ((int)s.size() <= k){
			while (j < n){
				if (s.find(a[j]) == s.end()){
					if ((int)s.size() == k) break;
				}
				s[a[j]]++;
				j++;
			}
			//cout << i << ' ' << j << '\n';
			cnt += (ll)(j - i);
		}
		s[a[i]]--;
		if (s[a[i]] == 0) s.erase(a[i]);
	}
	cout << cnt;
	
	
	return 0;
}