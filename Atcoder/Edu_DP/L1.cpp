//recursion
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)(1e15); 
int n;
vector<vector<ll>> memo;
vector<ll> a;
// lay max nhat 
ll dp(int l,int r){
    if (l == r) return memo[l][r] = a[l];
    ll &ans = memo[l][r];
    if (ans > -INF) return ans;
    ans = max(a[l] - dp(l + 1,r),a[r] - dp(l,r - 1));
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    memo.resize(n,vector<ll> (n,-INF));
    cout << dp(0,n - 1);
    return 0;
}