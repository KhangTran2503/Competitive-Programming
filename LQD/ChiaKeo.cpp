#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
int n, sum;
vector<int> a;
//vector<int> mask;
/**
void go(int u,int cur_sum,int remain_sum,int &ans){
    if (u == n + 1){
        //cout << remain_sum << '\n';
        if (cur_sum == 0) ans = max(ans,remain_sum);
        return;
    }
    for (int i = -1; i < 2; i++)
        go(u + 1,cur_sum + a[u]*i,remain_sum + a[u]*(int)(i == 1),ans);
}
**/

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n + 1);
    //mask.resize(n + 1);

  
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    /**    
    if (sum == 0){
        cout << sum;
        return 0;
    }

    if (n <= 13){
        int ans = 0;
        go(1,0,0,ans);
        cout << sum - ans;
        return 0;
    }
    **/
    int double_sum = (sum << 1);
    
    //cout << double_sum << '\n';
    /**
    vector<vector<int>> dp(n + 1,vector<int> (double_sum + 1,-INF));
    
    dp[0][sum] = 0;
    for (int i = 1; i <= n; i++){
        //if (a[i] == 0) continue;
        for (int j = 1; j <= double_sum; j++){
            dp[i][j] = max(dp[i][j],dp[i - 1][j]);
            if (j + a[i] <= double_sum) dp[i][j] = max(dp[i][j],dp[i - 1][j + a[i]]);
            if (j >= a[i] - sum) dp[i][j] = max(dp[i][j],dp[i - 1][j - a[i]] + a[i]);

        }    
    }
    cout << sum - dp[n][sum];
    **/

    vector<int> dp(double_sum + 1,-INF);
    vector<int> new_dp(double_sum + 1);
    dp[sum] = 0;
    
    for (int i = 1; i <= n; i++){
        new_dp.assign(double_sum + 1,-INF);

        for (int j = 1; j <= double_sum; j++){
            new_dp[j] = max(new_dp[j],dp[j]);
            if (j + a[i] <= double_sum) new_dp[j] = max(new_dp[j],dp[j + a[i]]);
            if (j >= a[i] - sum) new_dp[j] = max(new_dp[j],dp[j - a[i]] + a[i]);
        }
        dp = new_dp;
    }
    cout << sum - dp[sum];
    return 0;
}
