#include <bits/stdc++.h>
using namespace std;
int n, x;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> x;
	vector<pair<int,int>> a(n);
	
	for (int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	
	sort(a.begin(),a.end());
	for (int i = 0; i < n - 2; i++){
		for (int l = i + 1, r = n - 1; l < n - 1 && l < r; l++){
			while (l < r && a[i].first + a[l].first + a[r].first > x) r--;
			//cout << l << ' ' << r << '\n';
			if (l >= r) break;
			if (a[i].first + a[l].first + a[r].first == x){
				
				vector<int> idx(3);
				idx[0] = a[i].second;
				idx[1] = a[l].second;
				idx[2] = a[r].second;
				sort(idx.begin(),idx.end());
				for (int id: idx) cout << id + 1 << ' ';
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
