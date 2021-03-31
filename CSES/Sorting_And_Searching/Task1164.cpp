#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tup;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<tup> p(n);
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		p[i] = make_tuple(b,a,i);
	}
	
	sort(p.begin(),p.end());
	set<pair<int,int>> ans;
	
	ans.insert(make_pair(get<0>(p[0]),1));
	vector<int> col(n);
	col[get<2>(p[0])] = 1;

	for (int i = 1; i < n; i++){
		int a,b,id;
		tie(b,a,id) = p[i];
		auto it = ans.lower_bound(make_pair(a,-1));
		if (it == ans.begin()){
			col[id] = int(ans.size()) + 1;
			ans.insert(make_pair(b,col[id]));
		}
		else {
			it--;
			col[id] = it->second;
			ans.erase(it);
			ans.insert(make_pair(b,col[id]));
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < n; i++) cout << col[i] << ' ';
	return 0;
}
