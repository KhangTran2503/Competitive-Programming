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
const int Maxn = 2*int(1e6) + 5;
const ll Mod = (ll)(1e9) + 7;
vector<ll> fac(Maxn);
vector<ll> invfac(Maxn);
int c1, c2, r1, r2;

// hockey stick identity

ll fastpow(ll x,ll y){
    ll ans = 1;
    while (y){
        if (y & 1) ans = (ans * x) % Mod;
        x = (x * x) % Mod;
        y >>= 1;
    }
    return ans;
}

ll inv(ll x){
    return fastpow(x,Mod - 2);
}

void init(){
    fac[0] = 1;
    for (int i = 1; i < Maxn; i++) fac[i] = (fac[i - 1]*i) % Mod;
    invfac[Maxn - 1] = inv(fac[Maxn - 1]);
    for (int i = Maxn - 2; i >= 0; i--) invfac[i] = ((i + 1) * invfac[i + 1]) % Mod;

}
ll C(int k,int n){
    ll tmp = fac[n];
    tmp = (tmp * invfac[k]) % Mod;
    tmp = (tmp * invfac[n - k]) % Mod;
    return tmp;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> r1 >> c1 >> r2 >> c2;
    init();
    ll ans = ((C(r2 + 1,r2 + 1 + c2 + 1) - C(r1,r1 + 1 + c2)) - (C(r2 + 1,c1 + r2 + 1) - C(r1,c1 + r1)) + 4*Mod) % Mod;
    cout << ans; 
    return 0;
}