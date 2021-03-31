#include <bits/stdc++.h>
#define oo int(1e9)
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
typedef double db;
const ll MOD = (ll)(1e9) + 7;
int n, K;
vector<int> a;
vector<int> dp;
/// thuat toan tro choi
int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> K;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    dp.resize(K + 1);

    for (int i = 0; i <= K; i++)
        for (int x : a)
            if (i >= x && !dp[i - x]) dp[i] = 1;

    if (dp[K]) cout << "First";
    else cout << "Second";
	return 0;
}
