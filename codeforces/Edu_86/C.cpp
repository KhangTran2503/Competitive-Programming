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


ll calc(int g,ll b,ll l, ll r){
    
    ll ans = 0;
    ll q1 = (l/b);
    ll r1 = (l % b);
    ll q2 = (r/b);
    ll r2 = (r % b);
    
    if ((q1 == q2) && (q1 % g != 0)) ans += (ll)(r2 - r1 + 1);
    else {
        if (q1 % g != 0) ans += (ll)(b - r1);
        if (q2 % g != 0) ans += (ll)(r2 + 1);
        q1++; q2--;
        if (q1 <= q2){
            ll cnt = (q2 - q1 + 1) - (q2/g - (q1 - 1)/g);
            ans += (ll)b*cnt;
        }
    }
    return ans;
    
}


void solve(){
    int a, b, q;
    cin >> a >> b >> q;
    if (a > b) swap(a,b);
    int remain = b % a;
    int _a = a/__gcd(a,remain);
    while (q--){
        ll l, r;
        cin >> l >> r;
        if (remain == 0) cout << 0 << ' ';
        else cout << calc(_a,b,l,r) << ' '; 
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}