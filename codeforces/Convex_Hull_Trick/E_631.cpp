#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld INF = 1e18;

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
		return st[pos].eval(x);
	}
	
};

int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	
	// F[i] = a1*1 + a2*2 + ... + ai*i
	vector<ll> F(n + 1);
	for (int i = 1; i <= n; i++) F[i] = F[i - 1] + a[i]*(ll)i;
	
	// s[i] = a1 + a2 + ... + ai
	vector<ll> s(n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	
	
	ll ans = F[n];
	//Case 1: n -> 1 (CHT Max)
	Max_CHT cht_rev;
	//cht_rev.add_line(Line(0,0));
	cht_rev.add_line(Line(1,0));
	for (int i = 2; i <= n; i++){
		ll f = F[n] - a[i]*(ll)i + s[i - 1] + cht_rev.get_value(a[i]);
		ans = max(ans,f);
		cht_rev.add_line(Line(i,-s[i - 1]));
	}
		
	// Case 2: 1 -> n (CHT MAX)
	
	Max_CHT cht;
	
	cht.add_line(Line(-n,-s[n]));
	
	for (int i = n - 1; i >= 1; i--){
		ll f = F[n] - a[i]*(ll)i + s[i] + cht.get_value(-a[i]);
		ans = max(ans,f);
		cht.add_line(Line(-i,-s[i]));
	}
	
	cout << ans;
	return 0;
}

