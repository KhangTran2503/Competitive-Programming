/*	2021-06-18	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	ll ans = 0;
	stack<int> st;
	for (int i = 1; i <= n; i++){
		ans += (a[i] >> 1);
		if (a[i] % 2 == 0) continue;
		if (st.empty()) st.push(i % 2);
		else {
			if (st.top() != (i % 2)){
				ans++;
				st.pop();
			}
			else st.push(i % 2);
		} 
		
	}
	cout << ans;
	return 0;
}
