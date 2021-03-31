#include <bits/stdc++.h>
#define bitcount(s) __builtin_popcount(s)
using namespace std;
typedef long long ll;
const ll Mod = (ll)(1e9) + 7;
vector<vector<int>> a;

int getbit(int s,int k){
    return (s >> k) & 1;
}

void add(ll &a,ll b){
    a += b;
    if (a >= Mod) a -= Mod;
}
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n, vector<int> (n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];

    
    //dp[mask] la so luong cap sao cho ko ton tai 2 ng o 2 hang hoac 2 cot bat ki
    vector<ll> dp((1 << n));
    dp[0] = 1LL;
    for (int mask = 1; mask < (1 << n); mask++){
        int nn = __builtin_popcount(mask) - 1;
        //cout << nn << '\n';
        //if (nn == n) break;
        for (int i = 0; i < n; i++)
            if ((getbit(mask,i) == 1) && (a[nn][i] == 1)){
                int premask = (mask ^ (1 << i));
                add(dp[mask],dp[premask]);
            }
    }    

    cout << dp[(1 << n) - 1];
    return 0;
}