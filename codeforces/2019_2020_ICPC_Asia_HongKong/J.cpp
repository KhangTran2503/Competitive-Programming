// dp[pos][less][moddiff][presum]
// 5000*2*60*60
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = (ll)(1e9) + 7;
int memo[5000][2][60][60];
int pow10[5001];
int m;
string L, R;
int type;

int dp(int pos,bool high,int moddiff,int presum){
    if (pos == -1) return (moddiff == 0);
    int &ans = memo[pos][high][moddiff][presum];
    if (ans != -1) return ans;
    ans = 0;
    
    int maxdigit;
    if (type)
        maxdigit = (high) ? 9: R[pos] - '0';
    else 
        maxdigit = (high) ? 9: L[pos] - '0';

    for (int dg = 0; dg <= maxdigit; ++dg){
        int new_moddiff = (dg*(pow10[pos] - presum + m) % m + moddiff) % m;
        int new_presum = (presum + dg) % m;
        bool new_high = (high || dg < maxdigit); 
        ans = (ans + dp(pos - 1,new_high,new_moddiff,new_presum)) % Mod;
    }
    return ans;

}

void init_pow(int sz){
    pow10[0] = 1;
    for (int i = 1; i < sz; i++) pow10[i] = (pow10[i - 1]*10) % m;

}

void init(int sz){
        for (int pos = 0; pos < sz; pos++)
            for (int high = 0; high < 2; high++)
                for (int moddiff = 0; moddiff < m; moddiff++)
                        for (int presum = 0; presum < m; presum++)
                            memo[pos][high][moddiff][presum] = -1;
}

bool check(const string& a){
    int modx = 0;
    int modfx = 0;
    int presum = 0;
    for (int i = int(a.size()) - 1; i >= 0; i--){
        int dg = a[i] - '0';
        modx = (modx*10 + dg) % m;
        modfx = ((dg*presum) % m + modfx) % m;
        presum = (presum + dg) % m;
    } 
    return (modx == modfx);
}


void solve(){
    cin >> L;
    cin >> R;
    cin >> m;
    reverse(R.begin(),R.end());
    reverse(L.begin(),L.end());
    while (L.size() < R.size()) L.push_back('0');
    init_pow(R.size());
    init(R.size());
    type = 1;
    ll ans = dp(R.size() - 1,0,0,0);
    //cout << ans << '\n';
    type = 0;
    init(L.size());
    ans = (ans - (ll)dp(L.size() - 1,0,0,0) + Mod) % Mod;
    ans = (ans + (ll)(check(L))) % Mod;
    cout << ans << '\n';
    

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
