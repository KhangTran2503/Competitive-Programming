//implementation

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)(1e15);
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<ll>> dp(n,vector<ll> (n,-INF));

    for (int L = n - 1; L >= 0; L--)
        for (int R = L; R < n; R++)
            if (L == R) dp[L][R] = a[L];
            else dp[L][R] = max(a[L] - dp[L + 1][R],a[R] - dp[L][R - 1]);

    cout << dp[0][n - 1];        
    return 0;
}

