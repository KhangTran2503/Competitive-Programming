#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld INF  = (ld)(2e18);

struct Line{
	ll k, m;
	Line(ll _k,ll _m): k(_k), m(_m) {};
	ll eval(ll val){ return k*val + m;}
	ld intersect(const Line& o){
		return (ld)(m - o.m)/(ld)(o.k - k);
	}
};

struct Max_CHT{
	vector<Line> st;
	vector<ld> isect{-INF};
	void add_line(Line d){
		if (!st.empty()){
			if(st.back().k == d.k){
				if (st.back().m > d.m) return;
				while (!st.empty() && st.back().k == d.k && d.m >= st.back().m){
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
	
	ll get_value(ll x){
		assert(!st.empty());
		isect.emplace_back(INF);
		int pos = upper_bound(isect.begin(),isect.end(),(ld)x) - isect.begin() - 1;
		//for (auto v: isect) cout << v << ' ';
		//cout << '\n'; 
		isect.pop_back();
		return st[pos].eval(x);
	}
	
};

struct rectangle{
	ll x, y, a;
	rectangle(ll _x = 0,ll _y = 0,ll _a = 0): x(_x), y(_y),a(_a) {};
	bool operator < (const rectangle& o) const {
		return (x < o.x|| (x == o.x && y > o.y));
	};
	ll value(){
		return x*y - a;
	};
};


vector<rectangle> rec;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	rec.resize(n);
	for (int i = 0; i < n; i++){
		cin >> rec[i].x >> rec[i].y >> rec[i].a;
	
	}
	sort(rec.begin(),rec.end());
	
	
	Max_CHT cht;
	cht.add_line(Line(0,0));
	
	ll sum = 0;
	ll ans = -INF;
	for (int i = 0; i < n; i++){
		sum = cht.get_value(-rec[i].y) + rec[i].value();
		//cout << sum << '\n';
		ans = max(ans,sum);
		cht.add_line(Line(rec[i].x,sum));
	} 
	cout << ans;
	return 0;
}
