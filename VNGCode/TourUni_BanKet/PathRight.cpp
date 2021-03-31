/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define eb emplace_back
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

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vi> a(n + 1,vector<int> (n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) cin >> a[i][j];
    
    vector<vi> dp(n + 1,vi (n + 1,0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) dp[i][j] = max(dp[i - 1][j - 1],dp[i - 1][j]) + a[i][j];
    
    int j = 1;
    for (int i = 1; i <= n; i++)
        if (dp[n][i] > dp[n][j]) j = i;
    cout << dp[n][j] << '\n';
    int i = n;
    vi ans;
    while (i > 0 && j > 0){
        ans.eb(a[i][j]);
        if (dp[i][j] - a[i][j] == dp[i - 1][j]) i--;
        else i--, j--;
    }
    reverse(all(ans));
    for (int x: ans) cout << x << ' ';
    return 0;
}