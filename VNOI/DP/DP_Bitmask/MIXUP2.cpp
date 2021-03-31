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
using namespace std;
const db Pi = acos(-1);
ll dp[16][1 << 16];
int n, k;
int a[16];

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int u = 0; u < n; u++) dp[u][1 << u] = 1;

    for (int mask = 0; mask < (1 << n); mask++){
        vi bit;
        for (int i = 0; i < n; i++)
            if (getbit(mask,i)) bit.pb(i);
        for (int u: bit)
            for (int v: bit)
                if (abs(a[u]-a[v]) > k) dp[u][mask] += dp[v][offbit(mask,u)];
    }
    ll ans = 0;
    for (int u = 0; u < n; u++)
        ans += dp[u][(1 << n) - 1];
    cout << ans;
    return 0;
}
