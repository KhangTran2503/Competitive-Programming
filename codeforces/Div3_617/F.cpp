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
typedef tuple<int,int,int> tup;
const int INF = int(1e9);
const int Maxval = int(1e6);
// sort increasing g
int n, m;
vector<tup> edge;
vector<int> ans;
vector<vector<ii>> g;

bool dfs1(int par,int from,int to,int w){
    if (from == to) return true;
    for (ii v: g[from]){
        if (v.second == par) continue;
        if (dfs1(from,v.second,to,w)){
            ans[v.fir] = w;
            return true;
        }   
    }
    return false;
}

pair<bool,int> dfs2(int par,int from,int to){
    if (from == to) return {true,INF};
    for (auto v: g[from]){
        if (v.second == par) continue;
        auto pre = dfs2(from,v.second,to);
        if (pre.first){
            return {true,min(pre.second,ans[v.first])};
        }
    }
    return {false,INF};
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;;
        u--, v--;
        g[u].emplace_back(i,v);
        g[v].emplace_back(i,u);
    }
    
    cin >> m;
    ans.assign(n - 1,Maxval);
    edge.resize(m);
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge[i] = make_tuple(w,u,v);
        //dfs1(-1,u,v,w);
    }
    sort(all(edge));

    for (int i = 0; i < m; i++){
        int u, v ,w;
        tie(w,u,v) = edge[i];
        dfs1(-1,u,v,w);
    }

    for (int i = 0; i < m; i++){
        int u, v ,w;
        tie(w,u,v) = edge[i];
        if (w != dfs2(-1,u,v).sec){
            cout << -1;
            return 0;
        }
    }

    for (int x : ans) cout << x << ' ';

    return 0;
}