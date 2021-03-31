/*	2021-01-11	*/
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
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++){
		int x, d;
		cin >> x >> d;
		a[i] = {d,x};
	}
	sort(all(a));
	a.erase(unique(all(a),[&](pair<int,int> u,pair<int,int> v){return (u.first == v.first);}),a.end());
	
	int x;
	while (cin >> x){
		auto it = lower_bound(all(a),make_pair(x,-1));
		if (it == a.begin()) cout << (it->second) << '\n';
		else if (it == a.end()) cout << (prev(it)->second) << '\n';
		else {
			auto pre = it;
			pre--;
			if (abs(x - (it->first)) < abs(x - (pre->first))) cout << (it->second) << '\n';
			else if (abs(x - (it->first)) > abs(x - (pre->first))) cout << (pre->second) << '\n';
			else cout << min(it->second,pre->second) << '\n';
		}
	}
	return 0;
}