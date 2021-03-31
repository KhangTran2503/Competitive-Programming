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
#define N int(1e5)+5
using namespace std;
const db Pi = acos(-1);
vi g[N];
int n, m;
int a[N];
int dp[N],dpMax[N];
int par[N];

// DP on Tree

void creat(int u){
    for (int v : g[u])
        if (v != par[u]){
            par[v] = u;
            creat(v);
        }
}

int dfs(int u,int p){
    if (dpMax[u] != -1) return dpMax[u];
    if (u == 1){
        if (a[1] == 1){
            dp[1] = 1;
            return dpMax[1] = 1;
        }
        else {
            dp[1] = 0;
            return dpMax[1] = 0;
        }
    }

    int v = par[u];
    dpMax[u] = dfs(v,u);
    if (a[u] == 1 && a[v] == 1) {
            dp[u] = 1 + dp[v];
    }
    else {
        if (a[u] == 1) dp[u] = 1;
        else dp[u] = 0;
    }
    dpMax[u] = max(dp[u],dpMax[u]);
    return dpMax[u];


}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++){
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
        //deg[x] ++ , deg[y] ++;
    }
    creat(1);
    ms(dp,-1);
    ms(dpMax,-1);
    /*for (int i = 1; i <= n; i++) cout << dp[i] <<' ';
    cout << '\n';*/
    int ans = 0;
    for (int i = 2; i <= n; i++)
        if (g[i].size() == 1 && dfs(i,i) <= m) ans++;
    cout << ans;
    /*cout << '\n';
    for(int i = 1; i <= n; i++) cout << g[i].size() << ' ' << dp[i] << ' '<< dpMax[i] << '\n';*/
    return 0;
}
