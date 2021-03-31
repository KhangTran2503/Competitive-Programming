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
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
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
const db Pi = acos(-1);
map<int,int> Max;
map<int,int> id;
int dp[N];
int n, a[N], Pre[N]={0};
int ans  = 0, pos = 0;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        int Maxx = Max[a[i] - 1];
        dp[i] = Maxx+1;
        Pre[i] = id[a[i] - 1];
        int Maxxi = Max[a[i]];
        if (dp[i] > Maxxi){
            Max[a[i]] = dp[i];
            id[a[i]] = i;
        }
        if (dp[i] > ans ){
            ans = dp[i];
            pos = i;
        }
    }
    cout << ans << '\n';
    vi r;
    int u = pos;
    while (u){
        r.pb(u);
        u = Pre[u];
    }
    for (int i = sz(r) - 1; i >= 0; i--) cout << r[i] << ' ';
    return 0;
}
