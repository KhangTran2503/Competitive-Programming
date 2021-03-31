#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tup;
vector<int> a;
vector<int> l, r;
int n, m;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	a.resize(m);
	l.resize(n + 1);
	r.resize(n + 1);
	for (int &x: a) cin >> x;
	
	for (int i = m - 1; i >= 0; i--) l[a[i]] = i;
	for (int i = 0; i < m; i++) r[a[i]] = i;
	
	stack<int> st;
	vector<tup> res;
	for (int i = 0; i < m; i++){
		if ((i != r[a[i]]) || (i == l[a[i]])){
			st.push(a[i]);
		}
		if (i == r[a[i]]){
			if (!st.empty()){
				int u = st.top();
				if (a[i] != u){
					cout << -1;
					return 0;
				}
			}
			while (!st.empty() && a[i] == st.top()) st.pop();
			res.emplace_back(a[i],l[a[i]] + 1,r[a[i]] + 1);
		}
	}
	if (!st.empty()){
		cout << -1;
		return 0;
	}
	
	reverse(res.begin(),res.end());
	cout << (int)res.size() << '\n';
	for (auto t: res){
		int c, lef, rig;
		tie(c,lef,rig) = t;
		cout << c << ' ' << lef << ' ' << rig << '\n';
	}
	return 0;
}
