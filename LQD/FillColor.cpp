#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
const int INF = int(1e9);
int memo[5000][5000];
int n;
vector<int> a;

int dp(int l,int r){
    if (l == r) return memo[l][r] = 0;
    int &res = memo[l][r];
    if (res != -1) return res;
    res = INF;
    if (a[l] == a[r]){
        res = min(res,dp(l + 1,r - 1) + 1);
        // because a[l + 1,r - 1] != a[l];
    }
    else res = min(res,min(dp(l + 1,r),dp(l,r - 1)) + 1);

    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n);
    for (int &x: a) cin >> x;
    uni(a);
    n = a.size();

    memset(memo,-1,sizeof(memo));
    cout << dp(0,n - 1);
    return 0;
}
