/*	2021-02-23	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef tuple<int,int,int> tup;
const int INF = (int)(1e9) + 10;
vector<tup> seg;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	seg.resize(n);
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		seg[i] = make_tuple(l,-r,i);
	}
	sort(all(seg));
	map<int,int> d;
	vector<int> ans2(n);
	for (int i = 0; i < n; i++){
		int l, r, id;
		tie(l,r,id) = seg[i];
		r = -r;
		//cout << l << ' ' << r << ' ' << id << '\n';
		if (d.find(l) != d.end()) d.erase(l);
		if (d.lower_bound(r) != d.end()) ans2[id] = 1;
		d[r] = 1;
	}
	
	d.clear();
	vector<int> ans1(n);
	for (int i = n - 1; i >= 0; i--){
		int l, r, id;
		tie(l,r,id) = seg[i];
		r = -r;
		//cout << l << ' ' << r << ' ' << id << '\n';
		if (d.lower_bound(-r) != d.end()) ans1[id] = 1;
		d[-r] = 1;
	}
	
	for (int i = 0; i < n; i++) cout << ans1[i] << ' ';
	cout << '\n'; 
	for (int i = 0; i < n; i++) cout << ans2[i] << ' ';
	return 0;
}