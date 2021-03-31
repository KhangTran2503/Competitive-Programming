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
ll f[N][5];

ll fastpow(ll x,int y){
    ll ans = 1;
    while (y){
        if (y&1) ans = (ans * x) % Mod;
        x = (x * x) % Mod;
        y >>= 1;
    }
    return ans % Mod;
}
/// Goi f[i][j] la so cach dat cac so tu 1-> 4 vao cac o 1 -> i , sao cho co
/// dung j mau trung nhau
/// * Neu ko dat them mau moi vao vi tri i thi se lay j mau trong i-1 o phia trc
///     f[i][j] = f[i-1][j]*j
/// * Neu dat them mau moi vao vi tri i thi se lay (4-j+1) mau ko trung voi i-1 o phia trc
///     f[i][j] = f[i-1][j-1]*(4-j+1)
/// => f[i][j] = f[i-1][j]*j + f[i-1][j-1]*(4-j+1)         
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> m >> n >> k;

    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 4; j++) f[i][j] = (f[i-1][j]*j + (4-j+1)*(f[i-1][j-1])) % Mod;

    ll ans = 0;
    for (int i = k; i <= 4; i++)
        ans = (ans + (f[n][i]) % Mod ) % Mod;
    //cout << ans << '\n';
    cout << (ll)fastpow(ans,m);

    return 0;
}
