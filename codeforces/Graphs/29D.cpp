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
vector<vector<int>> g;

bool dfs(int u,int p,int to,vector<int> &path){

    if (u == to) return true;
    for (int v: g[u])
        if (v != p) 
            if (dfs(v,u,to,path)){
                path.eb(v);
                return true;
            }
    return false;
}   

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    int szleaf  = 0;
    for (int i = 2; i <= n; i++) szleaf += (sz(g[i]) == 1);
    //cout << szleaf << '\n';
    vector<int> leaf;
    leaf.eb(1);
    for (int i = 0; i < szleaf; i++){
        int x;
        cin >> x;
        leaf.eb(x);
    }
    leaf.eb(1);

    vector<int> ans;
    for (int i = 0; i < sz(leaf) - 1; i++){
        vi tmp; 
        dfs(leaf[i],-1,leaf[i + 1],tmp);
        if (tmp.empty()){
            cout << -1;
            return 0;
        }
        ans.eb(leaf[i]);
        reverse(all(tmp));
        for (int x: tmp) 
            if (x != leaf[i + 1]) ans.eb(x);
    }
    ans.eb(1);

    if (sz(ans) != 2*n - 1) cout << -1;
    else for (int x: ans) cout << x << ' ';
    

    
    return 0;
}