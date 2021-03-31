#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll memo[401][401];
vector<ll> a;
vector<ll> sum;
int n;

ll dp(int l,int r){
    if (l == r) return memo[l][r] = 0;
    ll &ans = memo[l][r];
    if (ans != -1) return ans;
    ans = (ll)(1e18);
    for (int k = l; k < r; k++)
        ans = min(ans,dp(l,k) + dp(k + 1,r));
    ans += sum[r] - sum[l - 1];
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n + 1);
    sum.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    memset(memo,-1,sizeof(memo));
    cout << dp(1,n);
    return 0;
}