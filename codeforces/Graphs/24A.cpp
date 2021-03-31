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
int n;
vector<vi> W,g;
vi path, visit;

void dfs(int u){
    path.eb(u);
    visit[u] = 1;
    for (int v: g[u])
        if (!visit[v]) dfs(v);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    
    W.resize(n + 1,vi (n + 1,0));
    g.resize(n + 1);
    int sumw = 0;
    for (int i = 0; i < n; i++){
        int u,v , w;
        cin >> u >> v >> w;
        sumw += w;
        W[v][u] = w;
        W[u][v] = 0;
        g[u].eb(v);
        g[v].eb(u);
    }

    int w1 = 0;
    visit.resize(n + 1);
    dfs(1);
    path.eb(1);
    for (int i = 0; i < sz(path) - 1; i++)
        w1 += W[path[i]][path[i + 1]];
    
    cout << min(w1,sumw - w1);
    return 0;
}