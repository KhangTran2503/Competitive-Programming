/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<ll,ll>
#define pb push_back
#define vi vector<int>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
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
const ll Mod = (ll)(1e9)+7;
ll n,k;
vector<ll> d;
ll cnt[N];
ll base[N];
ll cntd[N];

ll fastpow(ll x,ll y){
    ll ans = 1;
    while (y){
        if (y) ans = (ans*x)%Mod;
        x = (x*x)*Mod;
        y >>= 1;
    }
    return (ans + Mod) % Mod;
}

void extend_gcd(ll a,ll b, ll &x,ll &y){
    if (a == 0){
        x = 0;
        y = 1;
        return ;
    }
    ll x1, y1;
    extend_gcd(b%a,a,x1,y1);
    x = y1 - (b/a)*x1;
    y = x1;
}

ll inv(ll x){
    ll inv_x,y;
    extend_gcd(x,Mod,inv_x,y);
    inv_x = (inv_x+Mod)%Mod;
    return inv_x;

}
/// sai thuat
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> k;
    for (ll i = 1; i*i <= n; i++)
        if (n % i == 0) {
            d.pb(i);
            if (n/i != i) d.pb(n/i);
        }
    sort(all(d));
    //for (ll x: d) cout << x << ' ';
    //cout << '\n';
    for (int i = 0; i < d.size(); i++){
        cnt[i] = (d[i]*inv(d.size()) + Mod) % Mod;
    }
    if (n == 1){
        ll res = 0;
        for (int i = 0; i < d.size(); i++){
            res = (res + cnt[i]) % Mod;
        }
        cout << res;
        return 0;
    }

    cntd[d.size()-1] = d.size();
    for (int i = d.size() - 2; i >= 0; i--){
        ll tmp = 0;
        for (int j = i; j >= 0; j--)
            if (d[i] % d[j] == 0) tmp++;
       cntd[i] = tmp;
    }

    for (int i = 0; i < d.size(); i++){
        ll A = 0;
        for (int j = i; j < d.size(); j++)
            if (d[j] % d[i] == 0){
                A = (A + inv(cntd[j]) + Mod) % Mod;
            }
        A = fastpow(A,k-1);
        cnt[i] = (cnt[i]*A + Mod) % Mod;

    }

    ll res = 0;
    for (int i = 0; i < d.size(); i++){
        res = (res + cnt[i] + Mod) % Mod;
    }
    cout << res;
    return 0;
}
