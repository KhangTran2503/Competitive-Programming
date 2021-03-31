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
vii point;
vector<ll> Fr;
ll dp[105][105];
int n, m, k;
ll p;

/*
    Goi K la tap cac o cam + (1,1) + (n,m), size = k + 2

    Goi dpi,j la so duong di tu o i -> j trong tap K sao cho khong di qa o nao khac i ,j
    Ap dung Inclusion - Exclusion :
        Duong di i, j khong qua o cam nao = Tat ca duong di i, j - (Duong di i -> j qua it nhat 1 o)
        dpi,j = all_way(i, j) - sigma t (dpi,t * get_three(i,t,j))

        ** get_three(i,t,l) la duong di theo thu tu tang dan 

*/



void Init_Frac(){
    Fr.resize(n + m + 1);
    Fr[0] = 1;
    for (int i = 1; i <= n + m; i++)
        Fr[i] = (Fr[i - 1] * (ll)i) % p;
}

ll inv(ll x){
    ll y = p - 2;
    ll ans = 1;
    while (y){
        if (y & 1) ans = (ans * x) % p;
        x = (x * x) % p;
        y >>= 1;
    }
    return ans;
}

ll comb(int x,int y){
    int q = x + y;
    x = min(x,y);
    ll A = Fr[q];
    ll B = Fr[x] * Fr[q - x] % p;
    B = inv(B);
    return A*B % p;
}

ll all_way(int l,int r){
    int x = point[r].fir - point[l].fir;
    int y = point[r].sec - point[l].sec;
    if (y < 0) return 0;
    if (x == 0 || y == 0) if (l + 1 == r) return 1;
    return comb(x,y) % p;
}

ll get_three(int l,int r,int t){
    if ((point[t].sec > point[r].sec) || (point[t].sec < point[l].sec)) return 0;
    int x = point[r].fir - point[t].fir;
    int y = point[r].sec - point[t].sec;
    if (x == 0 || y == 0) return 1;
    return comb(x,y) % p;
}

ll calc_DP(int l,int r){
    if (l + 1 == r) return dp[l][r] = all_way(l,r) % p;
    if (dp[l][r] != -1) return dp[l][r] % p;
    ll ans = 0;
    for (int t = l + 1; t < r; t++)
        ans = ((ll)ans + ((ll)calc_DP(l,t) *(ll)(get_three(l,r,t))) % p ) % p;
    return dp[l][r] = (all_way(l,r) - ans + p) % p;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m >> k >> p;

    Init_Frac();
    point.pb(ii(1,1));
    for (int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        point.pb(ii(x,y));
    }
    point.pb(ii(n,m));
    sort(all(point));
    ms(dp, -1);
    cout << calc_DP(0,k + 1);
    return 0;
}
