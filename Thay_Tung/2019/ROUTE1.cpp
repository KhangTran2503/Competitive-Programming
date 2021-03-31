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
#define lcm(a,b) ((ll)(a)/__gcd((ll)(a),(ll)(b))*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
const db Pi = acos(-1);
int dp[1005][1005];
int n, m, p, k;

/// O(n^2)
/// Let dp(i,j) la so luong duong di thoa de bai 

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m >> k >> p;
    ms(dp,0);
    while (k --){
        int x, y;
        cin >> x >> y;
        dp[x][y] = -1;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ((i != 1 || j != 1) && dp[i][j] != -1){
                if (dp[i - 1][j] != -1) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % p;
                if (dp[i][j - 1] != -1) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % p;
            }
    cout << dp[n][m];


    return 0;
}
