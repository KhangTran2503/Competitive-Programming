#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld INF  = (ld)(1e18);

struct Line{
	ll k, m;
	Line(ll _k,ll _m): k(_k), m(_m) {};
	//bool operator < (const Line& o) const {return (k > o.k) || (k == o.k && m < o.m);}
	ll eval(ll val){ return k*val + m;}
	ll div(ll a,ll b){
		return a/b - ((a^b) < 0 && (a % b));
		//return (ll)floor((ld)a/(ld)b);
	}
	
	ll intersect(const Line& o){
		if (k == o.k) return (m > o.m) ? INF : -INF;
		return (ld)(m - o.m)/(ld)(o.k - k);
		//return div(m - o.m,o.k - k);
	}
};

struct Min_CHT{
	vector<Line> st;
	vector<ld> isect;
	void add_line(Line d){
		while (st.size() >= 2 && d.intersect(st[st.size() - 1]) <= st[st.size() - 1].intersect(st[st.size() - 2])){
			st.pop_back();
			//idx.pop_back();
		}
		st.push_back(d);
		//cout << st.size() << '\n';
		//idx.emplace_back((int)st.size() - 1);
	}
	
	void update(){
		isect.emplace_back(-INF);
		for (int i = 0; i < (int)st.size() - 1; i++)
			isect.emplace_back(st[i].intersect(st[i + 1]));
		isect.emplace_back(INF);
		//for (ll x: isect) cout << x << ' ';
		//cout << '\n';
	}
	ll get_value(ll x){
		assert(!st.empty());
		int pos = upper_bound(isect.begin(),isect.end(),x) - isect.begin() - 1;
		//assert(it == st.end());
		return st[pos].eval(x);
	}
	
};

vector<pair<ll,ll>> line;
int n;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	line.resize(n);
	for (auto &l: line) cin >> l.first >> l.second;
	sort(line.begin(),line.end(),[](auto u,auto v){return (u.first > v.first) || (u.first == v.first && u.second < v.second);});
	//sort(line.begin(),line.end());
	line.erase(unique(line.begin(),line.end(),[](auto u,auto v){return u.first == v.first;}),line.end());
	
	Min_CHT cht;
	for (auto l: line){
		cht.add_line(Line(l.first,l.second));
		//cout << l.first << ' ' << l.second << '\n';
	}
	cht.update();
	
	int m;
	cin >> m;
	while (m--){
		ll x;
		cin >> x;
		cout << cht.get_value(x) << '\n';
	}
	
	return 0;
}
