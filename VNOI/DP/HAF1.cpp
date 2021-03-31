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
int n, m;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<vector<int>> a(m + 1,vector<int> (n + 1));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    vector<vector<int>> dp(m + 1,vector<int> (n + 1,INF));


    for (int i = 0; i <= n; i++) dp[0][i] = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++) dp[i][j] = min(dp[i][j],dp[i - 1][j] + a[i][j]);
        vector<int> lef = dp[i];
        vector<int> rig = dp[i];
        for (int j = 2; j < n; j++){
            lef[j] = min(lef[j],lef[j - 1] + a[i][j]);
            rig[n - j + 1] = min(rig[n - j + 1],rig[n - j + 2] + a[i][n + 1 - j]);
        }
        for (int j = 2; j < n; j++)
            dp[i][j] = min(min(lef[j - 1],rig[j + 1]) + a[i][j],dp[i][j]);
    }

    
    int ans = INF;
    for (int j = 1; j <= n; j++) ans = min(ans,dp[m][j]);
    cout << ans;
    
    return 0;
}