#include <bits/stdc++.h>
using namespace std;
int n, k;
typedef pair<int,int> ii;
typedef long long ll;

multiset<int> mulmin,mulmax;
vector<int> a;
ll sum_min = 0, sum_max = 0;

// mulmin -> sum_max
// mulmax -> sum_min

void insert(int pos){
	if (!mulmax.empty() && a[pos] <= *prev(mulmax.end())){
		sum_min += (a[pos]);
		mulmax.insert(a[pos]);
	}
	else {
		sum_max += a[pos];
		mulmin.insert(a[pos]);
	}
	
	while (mulmax.size() > mulmin.size()){
		sum_min -= (*mulmax.rbegin());
		sum_max += (*mulmax.rbegin());
		mulmin.insert(*prev(mulmax.end()));
		mulmax.erase(prev(mulmax.end()));
	}

	while (mulmin.size() > mulmax.size()){
		sum_max -= (*mulmin.begin());
		sum_min += (*mulmin.begin());
		mulmax.insert(*mulmin.begin());
		mulmin.erase(mulmin.begin());
	}

}


void remove(int pos){
	if (pos < k) return;
	auto itmin = mulmin.find(a[pos - k]);
	auto itmax = mulmax.find(a[pos - k]);
	if (itmin != mulmin.end()){
		sum_max -= (*itmin);
		mulmin.erase(itmin);
	}
	else if (itmax != mulmax.end()){
		sum_min -= (*itmax);
		mulmax.erase(itmax);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++){
		remove(i);
		insert(i);
		if (i >= k){
			int median = *mulmax.rbegin();
			int size_min = (int)mulmax.size();
			int size_max = (int)mulmin.size();
			ll ans = (ll)(sum_max - size_max*median) + (ll)(size_min*median - sum_min);
			cout << ans << ' ';
		}

	}
	return 0;
}
