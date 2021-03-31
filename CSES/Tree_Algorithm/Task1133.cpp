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
vector<ll> numchild;
vector<ll> dp1, dp2;
int n;

// Tree distance II
// dp1[u] sum all distance subtree root u
// dp2[u] is sum all distance subtree par[u] not include u
// dp1[u] = dp1[v] + numchild[v] , v is children v
// dp2[u] = dp2[par] + dp1[par] - dp1[v] + n - 2*numchild[v]

void dfs_down(int u,int par){   
    numchild[u] = 1;
    for (int v: g[u])
        if (v != par){
            dfs_down(v,u);
            dp1[u] += (numchild[v] + dp1[v]);
            numchild[u] += numchild[v];
        }
}

void dfs_up(int u,int par){
    for (int v: g[u])
        if (v != par){
            dp2[v] = dp2[u] + dp1[u] - dp1[v] + (n - 2LL*numchild[v]);
            dfs_up(v,u);
        }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    g.resize(n + 1);
    numchild.resize(n + 1);
    dp1.resize(n + 1);
    dp2.resize(n + 1);
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    dfs_down(1,0);
    dfs_up(1,0);
    for (int i = 1; i <= n; i++) cout << dp1[i] + dp2[i] << ' ';
    return 0;
}