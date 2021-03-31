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
vi onecycle;
vi color, color2;
vector<vii> g;

int n, m, cycle_start = -1;

pair<bool,bool> dfs1(int u){
    color[u] = 1;
    for (auto uv: g[u]){
        int v = uv.sec;
        if (color[v] == 0){
            pair<bool,bool> ok = dfs1(v);
            if (ok.fir){
                if (ok.sec) onecycle.eb(uv.fir);
                if (v == cycle_start) return {true,false};
                else return {true,ok.sec};
            }
        }
        else if (color[v] == 1){
            cycle_start = v;
            onecycle.eb(uv.fir);
            return {true,true};
        }
    }
    color[u] = 2;
    return {false,false};
}

bool dfs2(int u,int id){
    color2[u] = 1;
    for (auto uv: g[u]){
        int v = uv.sec;
        if (uv.fir == id) continue;
        if (color2[v] == 0){
            if (dfs2(v,id)) return true;
        }
        else if (color2[v] == 1) return true;
    }
    color2[u] = 2;
    return false;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(i,v);
    }

    color.assign(n,0);
    for (int u = 0; u < n; u++){
        cycle_start = -1;
        if (!color[u] && dfs1(u).fir) break;
    }

    for (int id: onecycle){
        color2.assign(n,0);
        bool ok = true;
        for (int u = 0; u < n; u++)
            if (!color2[u] && dfs2(u,id)){
                ok = false;
                break;
            }
        if (ok) {
            cout << "YES\n";
            return 0;
        }
    }

    if (onecycle.empty()) cout << "YES";
    else cout << "NO";
    return 0;
}