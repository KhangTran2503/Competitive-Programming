
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
using namespace std;

void solve(int T){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai: a) cin >> ai;
    
    sort(all(a));
    
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int> (4,0)));

    dp[0][0][1] = dp[0][1][0] = dp[0][2][1] = 1;

    for (int i = 1; i < n; i++){
        for (int j = -1; j < 2; j++)
            for (int k = -1; k < 2; k++)
                for (int m = 0; m < 3; m++){
                    int nm = m + (k != 0);
                    if ( abs( (a[i - 1] + j)  - (a[i] + k)) <= 2){
                        dp[i][k + 1][nm] = max(dp[i][k + 1][nm],dp[i - 1][j + 1][m] + 1);
                    }
                    else dp[i][k + 1][nm] = 1; 
                }
    }


    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) 
            for (int m = 0; m < 3; m++)
                ans = max(ans,dp[i][j][m]);
    cout << "Case " << T << ": " << ans << '\n';

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}
