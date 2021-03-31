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
const ll Mod = (ll)(1e9)+7;
ll n , m;

ll fastpow(ll x, ll y){
    ll ans = 1;
    while (y){
        if (y&1) ans = (ans * x)%Mod;
        x = (x * x) * Mod;
        y >>= 1;
    }
    return ans;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    if (m > n){
        cout << 1;
        return 0;
    }
    if (m == n){
        cout << 2;
        return 0;
    }
    ll tmp = fastpow(2,n-m-1);
    tmp = (tmp + (n% Mod - m % Mod + Mod) % Mod)%Mod;
    if (n % m == 0) tmp = (tmp + 1)% Mod;
    cout << tmp;

    return 0;
}
