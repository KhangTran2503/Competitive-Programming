#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
int odd , even, n;
vector<int> a;
int memo[101][101][101][2];

// dp[pos][even][odd][state] la min xet toi vi tri pos, da dat even so chan, odd so le, ma tai pos ket qua cuoi la state
int dp(int pos,int od,int ev,int state){
    if (pos == n) return 0;
    int &ans = memo[pos][od][ev][state];
    if (ans != -1) return ans; 
    ans = INF;
    if (a[pos] > 0)
        ans = min(ans,dp(pos + 1,od,ev,a[pos] & 1) + int((a[pos] & 1) != state));
    else {
        if (od + 1 <= odd)
            ans = min(ans,dp(pos + 1,od + 1,ev,1) + (state != 1));
        if (ev + 1 <= even)
            ans = min(ans,dp(pos + 1,od,ev + 1,0) + (state != 0));
    }
    return ans;

}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;

    odd = (n + 1)/2;
    even = n/2;
    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] & 1) odd--;
        else if (a[i] > 0) even--;
    }
    //cout << odd << ' ' << even << '\n';
    memset(memo,-1,sizeof(memo));
    cout << min(dp(0,0,0,1),dp(0,0,0,0));
    return 0;
}