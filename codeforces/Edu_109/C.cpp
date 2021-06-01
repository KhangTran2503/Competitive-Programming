/*	2021-05-21	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef tuple<int,int,int> tup;
const int INF = (int)(1e9) + 10;
int n, m;


// luoi qua!!!
void solve(){
	cin >> n >> m;
	vector<tup> x(n);
	for (int i = 0; i < n; i++){
		cin >> get<0>(x[i]);
		get<1>(x[i]) = i;
	}
	for (int i = 0; i < n; i++){
		char c;
		cin >> c;
		get<2>(x[i]) = (int)(c == 'L');
	}

	// st save R
	stack<int> st[2];
	
	// queue save L
	queue<int> q[2];
	
	sort(all(x));
	vector<int> ans(n,-1);
	for (int i = 0; i < n; i++){
		int parity = (get<0>(x[i]) & 1);
		if (get<2>(x[i])){
			if (!st[parity].empty()){
				int u = st[parity].top();
				st[parity].pop();
				ans[get<1>(x[u])] = (get<0>(x[i]) - get<0>(x[u]))/2;
				ans[get<1>(x[i])] = ans[get<1>(x[u])];
			}
			else q[parity].push(i);
		}
		else st[parity].push(i);
		
	}
	
	// same L, R
	int u1, u2;
	// x[u2].first > x[u1].first 
	for (int parity = 0; parity < 2; parity++){
		// R
		while (st[parity].size() > 1){
			u1 = st[parity].top();
			st[parity].pop();
			u2 = st[parity].top();
			st[parity].pop();
			
			ans[get<1>(x[u1])] = abs(get<0>(x[u1]) - get<0>(x[u2]))/2 + (m - get<0>(x[u1]));
			ans[get<1>(x[u2])] = ans[get<1>(x[u1])];
		}
		// L
		
		while (q[parity].size() > 1){
			u1 = q[parity].front();
			q[parity].pop();
			u2 = q[parity].front();
			q[parity].pop();
			ans[get<1>(x[u1])] = abs(get<0>(x[u1]) - get<0>(x[u2]))/2 + get<0>(x[u1]);
			ans[get<1>(x[u2])] = ans[get<1>(x[u1])];
		}
		
		// L -> 0 -> R and R -> m -> L
		while (!st[parity].empty() && !q[parity].empty()){
			u1 = q[parity].front();
			q[parity].pop();
			
			u2 = st[parity].top();
			st[parity].pop();
			
			int dis;
			if (get<0>(x[u1]) <= m - get<0>(x[u2])) dis = m - get<0>(x[u2]) + (get<0>(x[u1]) + get<0>(x[u2]))/2;
			else dis = get<0>(x[u1]) + m -  (get<0>(x[u1]) + get<0>(x[u2]))/2;
			ans[get<1>(x[u1])] = dis;
			ans[get<1>(x[u2])] = dis;
		}
		
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
	
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}