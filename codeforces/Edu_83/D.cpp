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
const ll Mod = 998244353;
const int Maxn = 2*int(1e5);
int n, m;
vector<ll> fac(Maxn + 1), invfac(Maxn + 1);


ll fastpow(ll x,ll y){
    ll ans = 1;
    while (y){
        if (y & 1) ans = (ans * x) % Mod;
        x = (x*x) % Mod;
        y >>= 1;
    }
    return ans;
}

void init(){
    fac[0] = 1;
    for (int i = 1; i <= Maxn; i++)
        fac[i] = (fac[i - 1] * (ll)i) % Mod;
    
    invfac[Maxn] = fastpow(fac[Maxn],Mod - 2);
    for (int i = Maxn - 1; i >= 0; i--)
        invfac[i] = (invfac[i + 1]*(ll)(i + 1)) % Mod;
}

ll nCk(int k,int n){
    ll ans = fac[n];
    ans = (ans * invfac[k]) % Mod;
    ans = (ans * invfac[n - k]) % Mod;
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    ll ans = 0;
    if (n == 2) cout << 0;
    else {
        init();
        ans = nCk(n - 1,m);
        ans = (ans * fastpow(2,n - 3)) % Mod;
        ans = (ans * (ll)(n - 2)) % Mod;
        cout << ans;
    }
    return 0;
}