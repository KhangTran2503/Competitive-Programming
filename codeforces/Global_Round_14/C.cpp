#include <bits/stdc++.h>
using namespace std;
int n, m , x;
vector<pair<int,int>> h;

void solve(){
    cin >> n >> m >> x;
    h.resize(n);
    for (int i = 0; i < n; i++){
        cin >> h[i].first;
        h[i].second = i;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    
    sort(h.begin(),h.end());
    for (int i = 1; i <= m; i++) pq.push({0,i});
    
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        pair<int,int> u = pq.top();
        pq.pop();
        ans[h[i].second] = u.second;
        u.first += h[i].first;
        pq.push(u);
    }
    
    cout << "YES\n";
    for (int x: ans) cout << x << ' ';
    cout << '\n';
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}
