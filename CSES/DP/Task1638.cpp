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
const ll Mod = (ll)(1e9) + 7;
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<vector<char>> a(n,vector<char> (n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];

    vector<vector<ll>> dp(n,vector<ll> (n,0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            if (i ==0 && j == 0){
                if (a[i][j] == '.') dp[i][j] = 1;
            }
            else {
                if (i > 0 && a[i][j] == '.') dp[i][j] = (dp[i][j] + dp[i - 1][j]) % Mod;
                if (j > 0 && a[i][j] == '.') dp[i][j] = (dp[i][j] + dp[i][j - 1]) % Mod;
            }
        }
    cout << dp[n - 1][n - 1];
    return 0;
}