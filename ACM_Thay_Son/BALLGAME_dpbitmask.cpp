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
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N int(1e6)+5
using namespace std;
const db Pi = acos(-1);
const ll Mod = 1000000007;
int n, m, k;
ll dp[N][16];

ll fastpow(ll x,int y){
    ll ans = 1;
    while (y){
        if (y&1) ans = (ans * x) % Mod;
        x = (x * x) % Mod;
        y >>= 1;
    }
    return ans % Mod;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> m >> n >> k;

    for (int i = 0; i < 4; i++) dp[1][1 << i] = 1;
    for (int i = 2; i <= n; i++){
        for (int mask = 0; mask < 16; mask++){
            for (int j = 0; j < 4; j++)
                if (getbit(mask,j)){
                    dp[i][mask] = (dp[i-1][mask] + dp[i][mask]) % Mod;
                    dp[i][mask] = (dp[i][mask] + dp[i-1][offbit(mask,j)]) % Mod;
            }
        }
    }
    //cout << ans << '\n';
    ll ans = 0;
    for (int mask = 0; mask < 16; mask++)
        if (bitcount(mask) >= k) ans = (ans + dp[n][mask]) % Mod;
    cout << (ll)fastpow(ans,m);

    return 0;
}
