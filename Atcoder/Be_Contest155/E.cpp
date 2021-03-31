/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define matrix vector<vector<ll>>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define getbit(s,k) ((s >> k)&1)
#define turnbit(s,k) (s | (1<<k))
#define offbit(s,k) (s & ~(1<<k))
#define flipbit(s,k) (s ^ (1<<k))
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
using namespace std;
const int INF = int(1e9);

// dp[i][0..1] la xet toi vi tri so thu i thi dung phep s[i] hay 10 - s[i]
// dp[i][0] = dp[i - 1][0] + dg 
// dp[i][0] = dp[i - 1][1] + dg + 1  , vi (i - 1) muon 10 nen i phai cong them 1
// dp[i][1] = dp[i - 1][0] + 10 - dg
// dp[i][1] = dp[i - 1][1] + 10 - dg - 1, vi (i - 1) muon 10 nen i phai cong them 1

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n,vector<int> (2));
    dp[n - 1][0] = s[n - 1] - '0';
    dp[n - 1][1] = 10 - (s[n - 1] - '0');

    for (int i = n - 2; i >= 0; i--){
        int dg = s[i] - '0';
        dp[i][0] = min(dp[i + 1][0] + dg,dp[i + 1][1] + dg + 1);
        dp[i][1] = min(dp[i + 1][0] + 10 - dg,dp[i + 1][1] + 10 - dg - 1);
    }
    cout << min(dp[0][0],dp[0][1] + 1);
    return 0;
}