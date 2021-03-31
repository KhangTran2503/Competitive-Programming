#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = (ll)(1e9) + 7;
int n, M, K;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> M >> K;

    vector<ll> dp(n + 1);
    vector<ll> prefix_sum(n + 1);
    //for (int i = 0; i < K; i++) dp[i] = 0;
    ll all = 1;
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        if (i < K) dp[i] = (dp[i - 1]*M) % Mod;
        else{
            dp[i] = (prefix_sum[i - 1] - prefix_sum[i - K] + Mod) % Mod;
        }
        prefix_sum[i] = (prefix_sum[i - 1] + ((M - 1)*dp[i]) % Mod) % Mod;
        all = (all*M) % Mod;
    }
    cout << (all - dp[n] + Mod) % Mod;
    return 0;
}
