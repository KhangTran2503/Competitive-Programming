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
#define lcm(a,b) ((ll)(a)/__gcd((ll)(a),(ll)(b))*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
const db Pi = acos(-1);
vector<set<int>> g;
vector<int> deg;
int n, m, ans, rem;

/// cm dc ans = min(n, [n + m]/2)

void Remove(){
    if (rem == 0) return;
    vector<int> deg2 = deg;
    for (int u = 0; u < n; u++){
        priority_queue<ii> pq;
        for (int v: g[u]) pq.push(ii(deg2[v],v));
        while (!pq.empty() && deg2[u] > deg[u]/2 + (deg[u] % 2 != 0)){
            int degv = pq.top().fir;
            int v = pq.top().sec;
            pq.pop();
            if (degv <= deg[v] / 2 + (deg[v] % 2 != 0)) continue;
            deg2[u]--; deg2[v]--;
            g[u].erase(g[u].find(v));
            g[v].erase(g[v].find(u));
            rem--;
            if (rem == 0) return;
        }
    }
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    deg.resize(n);
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].insert(v);
        g[v].insert(u);
        deg[u]++; deg[v]++;
    }

    ans = min(m, (n + m)/ 2 + ((n + m) % 2 != 0));
    rem = m - ans;
    Remove();
    cout << ans << '\n';
    set<ii> Edge;
    for (int u = 0; u < n; u++)
        for (int v: g[u]) Edge.insert(ii(min(u,v),max(u,v)));
    for (ii uv: Edge) cout << uv.first + 1 << ' ' << uv.second + 1 << '\n';
    return 0;
}
