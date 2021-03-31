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
vector<vi> g;
vi dp1, dp2;
int n;
// dp1[u] max len in sub u
// dp2[u] max len in par u not include subtree u
void dfs(int u,int p){
    
    for (int v: g[u])
        if (v != p){
            dfs(v,u);
            dp1[u] = max(dp1[u],dp1[v] + 1);
        }
}

void dfs_up(int u,int p){
    vi lefchild;
    vi rigchild;
    vi child;
    for (int v: g[u])
        if (v != p){
            lefchild.eb(dp1[v]);
            child.eb(v);
        }
    rigchild = lefchild;
    int m = sz(lefchild);
    for (int i = 1; i < m; i++) lefchild[i] = max(lefchild[i],lefchild[i - 1]);
    for (int i = m - 2; i >= 0; i--) rigchild[i] = max(rigchild[i + 1],rigchild[i]);
    for (int i = 0; i < m; i++){
        int v = child[i];
        dp2[v] = max(dp2[v],dp2[u] + 1);
        if (i > 0) dp2[v] = max(dp2[v],lefchild[i - 1] + 2);
        if (i < m - 1) dp2[v] = max(dp2[v],rigchild[i + 1] + 2);
    }
    for (int v: child) dfs_up(v,u);
}



int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    g.resize(n + 1);
    dp1.resize(n + 1);
    dp2.resize(n + 1);

    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }
    dfs(1,0);
    dfs_up(1,0);
    for (int i = 1; i <= n; i++) cout << max(dp1[i],dp2[i]) << ' ';
    return 0;
}