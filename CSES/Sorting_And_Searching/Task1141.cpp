#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> p(n);
	for (int &x: p) cin >> x;

	map<int,int> d;

	int last = -1;
	int ans = 0;
	for (int i = 0, j = 0; i < n; i++){
		while (j < n && d[p[j]] < 1){
			d[p[j]]++;
			j++;
		};
		ans = max(ans,j - i);
		d[p[i]]--;
	}
	cout << ans;
	return 0;
}
