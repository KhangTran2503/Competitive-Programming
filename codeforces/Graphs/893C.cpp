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
#define N int(1e5)+5
using namespace std;
vi g[N];
int n,m;
ll c[N];
ll res = 0;
bool visit[N];

ll dfs(int u){
    visit[u] = 1;
    ll tmp = c[u];
    for (int v: g[u])
        if (!visit[v]) tmp = min(tmp,dfs(v));
    return tmp;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++){
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    ms(visit,0);
    for (int i = 1; i <= n; i++)
        if (!visit[i]) res+= dfs(i);

    cout << res;
    return 0;
}
