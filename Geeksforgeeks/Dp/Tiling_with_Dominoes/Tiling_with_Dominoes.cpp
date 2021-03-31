///  dp[i][0] : of way to completely fill a 3xn board
///  dp[i][1] : of ways to fill a 3 x n board with top/bottom corner in last column not filled 
#include<bits/stdc++.h>
using namespace std;
int dp[105][2], n;

int main(){
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    dp[1][0] = 0; dp[2][0] = 3;
    dp[1][1] = 1; dp[2][1] = 0;
    for (int i = 3; i <= n ; i++){
        dp[i][0] = dp[i-2][0] + 2*dp[i-1][1];
        dp[i][1] = dp[i-2][1] + dp[i-1][0];
    }
    cout<< dp[n][0];
    return 0;
}
