#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
int n;
ll s;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	vector<ii> a(n);
	for (int i = 0; i < n; i++){
		ll x;
		cin >> x;
		a[i] = {x,i};
	}

	sort(a.begin(),a.end());

	for (int i = 0; i < n - 3; i++)
		for (int j = i + 1; j < n - 2; j++)
			for (int k = j + 1, h = n - 1; k < n - 1 && k < h; k++){
				while (h > k && a[i].first + a[j].first + a[k].first + a[h].first > s) h--;
				if (h <= k) break;
				if (a[i].first + a[j].first + a[k].first + a[h].first == s){
					vector<int> id{a[i].second,a[j].second,a[k].second,a[h].second};
					sort(id.begin(),id.end());
					for (int x: id) cout << x + 1 << ' ';
					return 0;
				}
			}
	cout << "IMPOSSIBLE";
	return 0;
}
