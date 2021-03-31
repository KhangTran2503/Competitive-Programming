#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld INF = 2e18;

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
		//isect.emplace_back(INF);
		int pos = upper_bound(isect.begin(),isect.end(),(ld)x) - isect.begin() - 1;
		//isect.pop_back();
		assert(pos < (int)st.size());
		return st[pos].eval(x);
	}
	
};

int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<ll> a(n + 1), s(n + 1), F(n + 1);
	
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		F[i] = F[i - 1] + s[i];
	}
	
	ll ans = -(ll)INF;
	Max_CHT cht;
	for (int i = n; i >= 1; i--){
		cht.add_line(Line(-i,F[i]));
		ll f = cht.get_value(s[i - 1]) - F[i - 1] + (ll)(i - 1)*s[i - 1];
		ans = max(ans,f);
	}
	cout << ans;
	return 0;
}
