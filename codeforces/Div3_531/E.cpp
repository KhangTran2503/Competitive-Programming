/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<int,int>
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
#define N 2*int(1e5)+5
using namespace std;
const ll Mod = 998244353;
map<int,int> d;
vector<ii> seg;
int a[N];
int n;

ll fastpow(ll x, ll y) {
    ll ans = 1;
    while (y){
        if (y&1) ans = (ans * x) % Mod;
        x = (x * x) % Mod;
        y >>= 1;
    }
    return ans;
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (d[a[i]] == 0) d[a[i]] = i;
        else seg.push_back(ii(d[a[i]],i));
    }
    sort(all(seg));
    ll cnt = 0;
    ll sum = 0;
    for (int i = 0; i < sz(seg); ){
        int j = i;
        int R = seg[i].sec;
        while (j < sz(seg) && seg[j].fir <= R){
            R = max(R, seg[j].sec);
            j++;
        }
        sum+= (ll)(R - seg[i].fir + 1);
        cnt ++;
        i = j;
    }
    //cout << cnt << '\n';
    //cout << sum << '\n';
    cnt += (ll)(n - sum);
    //cout << cnt << '\n';
    cout << fastpow(2LL,cnt-1);
    return 0;
}
