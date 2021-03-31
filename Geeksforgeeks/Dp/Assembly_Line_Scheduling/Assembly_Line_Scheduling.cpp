#include<bits/stdc++.h>
#define N int(1e5)+5
using namespace std;
int dp[N][3], t[N][3], a[N][3];
int n, e1, e2, x1, x2;

int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> e1 >> e2 >> x1 >> x2;
    for (int i = 1; i <= n; i++){
        cin >> t[i][1] >> t[i][2] >> a[i][1] >> a[i][2];
    }

    dp[1][1] = e1 + a[1][1];
    dp[1][2] = e2 + a[1][2];
    for (int i = 2; i <= n; i++){
        dp[i][1] = min(dp[i-1][1]+a[i][1], dp[i-1][2]+a[i][1]+t[i][2]);
        dp[i][2] = min(dp[i-1][2]+a[i][2], dp[i-1][1]+a[i][2]+t[i][1]);
    }
    cout << min(dp[n][1]+x1, dp[n][2]+x2) << '\n';
    return 0;
}
