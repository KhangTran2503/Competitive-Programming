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
const ll Inv2 = (Mod + 1) >> 1;
ll n;

// sum(x -> y)
ll getsum(ll x,ll y){
    ll sumx = ((x % Mod)*((x - 1) % Mod)) % Mod;
    ll sumy = ((y % Mod)*((y + 1) % Mod)) % Mod;
    return ((sumy - sumx  + Mod)*Inv2) % Mod;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;    
    ll ans = 0;

    ll lastnum = n;
    ll firstnum = n + 1;
    while (lastnum  > 0)
    {
        ll remain = n/lastnum;
        firstnum = n/(remain + 1) + 1;
        ans = (ans + (getsum(firstnum, lastnum) * remain) % Mod) % Mod;
        lastnum = firstnum - 1;
    }
    cout << ans;
    return 0;
}