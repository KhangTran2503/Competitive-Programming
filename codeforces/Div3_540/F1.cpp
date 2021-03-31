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
#define N 3*int(1e5)+5
using namespace std;
const db Pi = acos(-1);
ll cnt[N][2];
int n;
int a[N];
vi g[N];
int ans = 0;
int visit[N] = {0};
void dfs1(int u){
    visit[u] = 1;
    if (a[u] == 1) cnt[u][0] = 1;
    if (a[u] == 2) cnt[u][1] = 1;
    for (int v : g[u]){
        if (visit[v]) continue;
        dfs1(v);
        cnt[u][0] += cnt[v][0];
        cnt[u][1] += cnt[v][1];
    }

    //cout << u <<' ' << cnt[u][0] << ' ' << cnt[u][1] << '\n';

}

void dfs2(int u){
    visit[u] = 1;
    for (int v : g[u]){
        if (visit[v]) continue;
        if ((cnt[v][1] == 0 || cnt[v][0] == 0) && (cnt[1][0] - cnt[v][0] == 0 || cnt[1][1] - cnt[v][1] == 0)) ans ++;
        dfs2(v);
    }
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ms(visit,0);
    dfs1(1);
    ms(visit,0);
    dfs2(1);
    cout << ans;
    return 0;
}
