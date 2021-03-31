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
vector<vector<int>> g;
int n, m, k;

void bfs(int from,vi &d){
    fill(all(d),-1);
    d[from] = 0;
    queue<int> q;
    q.push(from);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v: g[u])
            if (d[v] == -1){
                d[v] = d[u] + 1;
                q.push(v);
            }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    vector<int> spec(k);
    for (int &i: spec) cin >> i, i--;

    g.resize(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vi f(n), g(n);
    bfs(0,f);
    bfs(n - 1,g);
    // f[u] : minimal distance from 1 to u
    // g[u] : minimal distance from n - 1 to u
    // Max( min(f[u] + g[v],f[v] + g[u])) 
    // Suppose: f[u] + g[v] <= f[v] + g[u]   <=> f[u] - g[u] <= f[v] - g[v]
    // So that: sort non decreasing f[u] - g[u]
    // for each u find   Maxf[v] such that v < u
    // update ans = max(g[u] + Maxf[v] + 1)

    vector<ii> delta(k);
    for (int i = 0; i < k; i++) delta[i] = {f[spec[i]] - g[spec[i]],spec[i]};

    sort(all(delta));
    int ans = 0;
    int maxf = -INF;
    for (auto it: delta){
        int id = it.sec;
        ans = max(ans,g[id] + maxf + 1);
        maxf = max(maxf,f[id]);
    }
    ans = min(ans,g[0]);
    cout << ans;
    return 0;
}