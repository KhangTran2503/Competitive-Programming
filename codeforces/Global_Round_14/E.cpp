/* DP O(n^3)

Can DP(O^2) using dp trick: dp component

*/


#include <bits/stdc++.h>
using namespace std;
int n, M = 100;
int C[505][505];
int pw2[505];

void add(int &a,int b){
    a += b;
    if (a >= M) a -= M;
}

void mult(int &a,int b){
    a = (1LL*a*b) % M;
}


void init(){
    for (int i = 0; i < 501; i++) C[0][i] = 1;
    for (int i = 1; i < 501; i++)
        for (int j = 1; j <= i; j++)
            C[j][i] = (C[j - 1][i - 1] + C[j][i - 1]) % M;
    
    pw2[0] = 1;
    for (int i = 1; i < 501; i++)
        pw2[i] = (pw2[i - 1]*2) % M;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> M;
    init();

    vector<vector<int>> dp(n + 1,vector<int> (n + 1,0));

    for (int i = 1; i <= n; i++) dp[i][i] = pw2[i - 1];
    
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++){
            int upper_k = min(i - 2,j);
            for (int k = 1; k <= upper_k; k++){
                int tmp = dp[i - (k + 1)][j - k];
                mult(tmp,pw2[k -1]);
                mult(tmp,C[k][j]);
                add(dp[i][j],tmp);
                //dp[i][j] = (dp[i][j] + (dp[i - (k + 1)][j - k]*pw2[k - 1]*C[k][j]) % M) % M;
            }
        }

    /*
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= i; j++) cout << dp[i][j] << ' ';
        cout << '\n';
    }
    */

    
    int ans = 0;
    for (int i = 0; i <= n; i++) add(ans,dp[n][i]);
    cout << ans;
    return 0;
}
