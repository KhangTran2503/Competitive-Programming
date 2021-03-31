#include<bits/stdc++.h>
using namespace std;

int n, m;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	multiset<int> mus;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		mus.insert(x);
	}

	for (int i = 0; i < m; i++){
		int x;
		cin >> x;
		if (mus.empty()){
			cout << -1 << '\n';
			continue;
		}
		auto it = mus.upper_bound(x);
		if (it == mus.begin()) cout << -1 << '\n';
		else {
			it--;
			cout << *it << '\n';
			mus.erase(it);
		}
		
	}
	return 0;
}
