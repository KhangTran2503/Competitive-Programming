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
#define oo (int)(1e9)+5
#define N int(1e5)+5
using namespace std;
vector<ii> g[N];
int a[N], d[N]={0};
int n, m, k;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb(ii(w,v));
        g[v].pb(ii(w,u));
    }

    for (int i = 1 ; i <= k; i++) {
        cin >> a[i];
        d[a[i]] =1;
    }

    if (k == 0){
        cout << -1;
        return 0;
    }

    int res = oo;
    for (int i = 1; i <= k; i++){
        for (ii adj : g[a[i]])
            if (!d[adj.sec]) res = min(res,adj.fir);
    }

    if (res != oo) cout << res;
    else cout << -1;
    return 0;
}
