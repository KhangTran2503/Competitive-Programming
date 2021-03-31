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
int a, b;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> a >> b;
    vector<vector<int>> dp(a + 1,vi (b + 1,INF));

    for (int x = 1; x <= a; x++)
        for (int y = 1; y <= b; y++)
            if (x == y) dp[x][y] = 1;
            else {
                for (int r = 1; r <= (x + 1)/2; r++)
                    dp[x][y] = min(dp[x][y],dp[x - r][y] + dp[r][y]);

                for (int c = 1; c <= (y + 1)/2; c++)
                    dp[x][y] = min(dp[x][y],dp[x][y - c] + dp[x][c]);
            }
    cout << dp[a][b] - 1;
    return 0;

}