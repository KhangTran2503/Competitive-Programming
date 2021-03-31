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
int T;
ll a, m;

ll f(ll lef,ll rig,ll diff){
    return (rig/diff) - ((lef - 1LL)/diff);
}

void Solve(){
    cin >> a >> m;
    ll g = gcd(a,m);
    //cout << g << '\n';
    ll lef = a/g;
    ll rig = (a + m - 1LL)/g;

    m /= g;

    vector<ll> prime;
    for (ll i = 2; i*i <= m; i++)
        if (m % i == 0){
            prime.emplace_back(i);
            while (m % i == 0) m /= i;
        }
    if (m > 1) prime.emplace_back(m);
    int n = prime.size();
    //Inclusion-Exclusion
    ll ans = f(lef,rig,1);
    for (int mask = 1; mask < (1 << n); mask++){
        ll diff = 1;
        for (int i = 0; i < n; i++)
            if (getbit(mask,i)) diff *= (ll)prime[i];
        if (bitcount(mask) & 1) ans -= f(lef,rig,diff);
        else ans += f(lef,rig,diff);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) Solve();
    return 0;
}