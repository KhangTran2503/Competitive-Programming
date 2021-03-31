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
vector<int> ans[2];
vector<vector<int>> g;
vector<int> used;
int n, m;
void clear(){
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 0; i < 2; i++) ans[i].clear();
    used.clear();
}

void dfs(int u,int col){
    used[u] = 1;
    ans[col].pb(u);
    for (int v: g[u])
        if (!used[v]) dfs(v,1 - col);
}


int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        cin >> n >> m;


        g.resize(n);
        used.resize(n,0);
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
            //deg[u]++; deg[v]++;
        }
        dfs(1,0);
        if (ans[0].size() > ans[1].size()) ans[0] = ans[1];
        cout << ans[0].size() << '\n';
        for (int x: ans[0]) cout << x + 1 << ' ';
        cout << '\n';
        clear();
    }

    return 0;
}
