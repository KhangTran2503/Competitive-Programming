#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld INF  = (ld)(1e18);

struct Line{
	ll k, m;
	Line(ll _k,ll _m): k(_k), m(_m) {};
	//bool operator < (const Line& o) const {return (k < o.k) || (k == o.k && m < o.m);}
	ll eval(ll val){ return k*val + m;}
	//bool parallel(const Line& o){return k == o.k;}
	ld intersect(const Line& o){
		return (ld)(m - o.m)/(ld)(o.k - k);
	}
};

struct Min_CHT{
	vector<Line> st;
	vector<ld> isect{-INF};
	void add_line(Line d){
		if (!st.empty()){
			if(st.back().k == d.k){
				if (st.back().m <= d.m) return;
				while (!st.empty() && st.back().k == d.k && d.m <= st.back().k){
					st.pop_back();
					isect.pop_back();
				}
			}
		}
		while (st.size() >= 2 && d.intersect(st[st.size() - 1]) <= st[st.size() - 1].intersect(st[st.size() - 2])){
			st.pop_back();
			isect.pop_back();
		}
		if (st.size() > 0) isect.emplace_back(st.back().intersect(d));
		st.push_back(d);
	}
	
	//void update(){
		//isect.emplace_back(-INF);
		//for (int i = 0; i < (int)st.size() - 1; i++)
			//isect.emplace_back(st[i].intersect(st[i + 1]));
		//isect.emplace_back(INF);
	
	//}
	ll get_value(ll x){
		assert(!st.empty());
		isect.emplace_back(INF);
		int pos = upper_bound(isect.begin(),isect.end(),x) - isect.begin() - 1;
		isect.pop_back();
		return st[pos].eval(x);
	}
	
};

vector<pair<ll,ll>> line;
int n;
ll c;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> c;
	vector<ll> a(n), b(n);
	for (ll &ai: a) cin >> ai;
	for (ll &bi: b) cin >> bi;
	
	Min_CHT cht;
	cht.add_line(Line(b[0],(ll)c));
	
	ll ans = 0;
	for (int i = 1; i < n; i++){
		ans = cht.get_value(a[i]);
		//cout << ans << '\n';
		cht.add_line(Line(b[i],ans));
	} 
	cout << ans;
	return 0;
}
