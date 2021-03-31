#include <bits/stdc++.h>
using namespace std;
int n, k;
typedef pair<int,int> ii;
multiset<int> mulmin,mulmax;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++){
		if (i >= k){
			auto itmin = mulmin.find(a[i - k]);
			auto itmax = mulmax.find(a[i - k]);
			if (itmin != mulmin.end()) mulmin.erase(itmin);
			else if (itmax != mulmax.end()) mulmax.erase(itmax);
		}

		if (!mulmax.empty() && a[i] <= *prev(mulmax.end())) mulmax.insert(a[i]);
		else mulmin.insert(a[i]);
		while (mulmax.size() > mulmin.size()){
			mulmin.insert(*prev(mulmax.end()));
			mulmax.erase(prev(mulmax.end()));
		}

		while (mulmin.size() > mulmax.size()){
			mulmax.insert(*mulmin.begin());
			mulmin.erase(mulmin.begin());
		}

		if (i >= k){
			cout << *prev(mulmax.end()) << ' ';
		}

	}
	return 0;
}
