#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<double>> dp(n,vector<double> (b + 1,0.0));
    
    for (int i = 1; i <= min(b,6); ++i) dp[0][i] = 1.0/6;

    for (int i = 1; i < n; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= min(6,j); k++)
                dp[i][j] += (1.0/6)*dp[i - 1][j - k];
    
    double ans = 0;
    for (int i = a; i <= b; i++) ans += dp[n - 1][i];
    cout << fixed << setprecision(6) << ans;
    return 0;
}
