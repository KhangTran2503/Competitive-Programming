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
vi color;
int n, m;

bool dfs(int u,int col){
    color[u] = col;
    for (int v: g[u]){
        if (color[v] == 0){
            if (!dfs(v,3 - col)) return false;
        }
        else {
            if (color[u] == color[v]) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    color.resize(n + 1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        g[b].eb(a);
    }

    bool valid = true;
    for (int i = 1; i <= n; i++)
        if (color[i] == 0){
            valid &= dfs(i,1);
        }
    if (valid) for (int i = 1; i <= n; i++) cout << color[i] << ' ';
    else cout << "IMPOSSIBLE";
    return 0;
}