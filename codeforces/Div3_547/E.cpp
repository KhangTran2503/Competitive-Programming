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
#define oo (ll)(1e13)
#define N 2*int(1e5) + 5
using namespace std;
const db Pi = acos(-1);
ll H;
ll a[N];
int n;

int check(ll x){
    if (x <= 0) return 0;
    for (int i = 1; i <= n; i++){
        x += a[i];
        if (x <= 0) return i;
    }
    return -1;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> H >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll Sum = 0;
    for (int i = 1; i <= n ; i++) {
        Sum += a[i];
        if (H + Sum <= 0){
            cout << i;
            return 0;
        }
    }


    if (Sum >= 0){
        cout << -1;
        return 0;
    }

    ll l = 0, r = (H/ abs(Sum)) + 1;
    ll ans = -1;
    while (l <= r){
        ll mid = (l + r) >> 1;
        ll u = H + mid*Sum;
        //cout << u << '\n';
        int pos = check(u);
        if (pos != -1){
            ans = mid * (ll)n + (ll)pos;
            r = mid - 1;
        }
        else l = mid + 1;

    }
    cout << ans;
    return 0;
}
