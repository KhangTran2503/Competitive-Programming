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
const ll Mod = (ll)(1e9);
vector<vector<ll>> fen;
int n, k;

ll get(int pos,int id){
    ll sum = 0;
    for ( ; id > 0 ; id -= (id & -id)) sum = (sum + fen[pos][id]) % Mod;
    return sum;
}

void update(int pos,int id,ll val){
    for (; id <= n; id += (id & -id)) fen[pos][id] = (fen[pos][id] + val) % Mod;
}

// dp[k][i] la day nghich the do dai k ket thuc tai i

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    
    vector<vector<ll>> dp(k + 1,vector<ll> (n + 1));
    fen.resize(k + 1,vector<ll> (n + 1));
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i], dp[1][i] = 1;

    for (int i = 2; i <= k; i++)
        for (int j = n; j >= 1; j--){
            dp[i][j] = get(i - 1,a[j] - 1);
            update(i - 1,a[j],dp[i - 1][j]);
        }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + dp[k][i]) % Mod;
    cout << ans;
    return 0;
}