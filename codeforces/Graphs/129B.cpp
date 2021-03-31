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
#define N 105
using namespace std;
int deg[N];
vi g[N];
int n, m;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        deg[u] ++;
        deg[v] ++;
    }

    int res = 0;
    while (1){
        bool ok = false;
        vi r;
        for (int u = 1; u <= n; u++)
            if (deg[u] == 1){
                ok = true;
                deg[u]--;
                r.pb(u);
            }
        if (!ok) break;
        res ++;
        for (int u: r)
            for (int v : g[u]) deg[v]--;
    }
    cout << res;
    return 0;
}
