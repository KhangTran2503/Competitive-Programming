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
int n;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    ll ans = 0;
    vii a(n+1);
    a[0] = ii(0,0);
    for (int i = 1; i <= n; i++) cin >> a[i].fir >> a[i].sec;
    uni(a);
    if (sz(a) == 1){
        cout << 1;
        return 0;
    }
    for (int i = 1; i < sz(a); i++){
        if (a[i].fir == a[i].sec && i < sz(a) - 1) ans--;
        int l = max(a[i-1].fir,a[i-1].sec);
        int r = min(a[i].fir,a[i].sec);
        ans += (ll)max(r - l + 1, 0);
    }
    cout << ans;
    return 0;
}
