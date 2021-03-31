#include <bits/stdc++.h>
using namespace std;
int n, m;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<vector<int>> dp(n + 1,vector<int> (m + 1));

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> x;
            if (x == 1) dp[i][j] = min(dp[i - 1][j - 1],min(dp[i - 1][j],dp[i][j -1])) + 1;
            else dp[i][j] = 0;
            ans = max(ans,dp[i][j]);
        }
    cout << ans;
    return 0;
}
