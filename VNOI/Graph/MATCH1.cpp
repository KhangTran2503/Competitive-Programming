/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define eb emplace_back
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
int n, m;
vi visit, match;
vector<vector<int>> g;
int ans  = 0;

// Find AugmentingPath
int Aug(int u){
    if (visit[u]) return 0;
    visit[u] = 1;
    for (int v: g[u])
        if (match[v] == -1 || Aug(match[v])){
            match[v] = u;
            return 1;
        }

    return 0;
}


// Maximun Cardinality Bipartite Matching
void MCBM(){
    for (int u = 0; u < m; u++){
        visit.assign(m,0);
        ans += Aug(u);
    }
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("test.inp","r",stdin);
    cin >> m >> n;
    g.resize(m);
    match.assign(n, -1);
    
    int u, v;
    while (cin >> u >> v){
        u--, v--;
        g[u].eb(v);
    }

    MCBM();
    cout << ans << '\n';
    for (int v = 0; v < n; v++)
        if (match[v] != -1) cout << match[v] + 1 << ' ' << v + 1 << '\n';

    return 0;
}