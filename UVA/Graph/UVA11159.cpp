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
vector<vector<int>> g;
vi visit, match;

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

// in bipartite graph (minimun vertex cover = maximun matching) 
void solve(int T){
    int n, m;
    cin >> n; vi a(n);
    for (int &x: a) cin >> x, x = abs(x);
    cin >> m; vi b(m);
    for (int &x: b) cin >> x, x = abs(x);

    g.assign(n,vector<int> ());
    // build graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            if (a[i] == 0){
                if (b[j] == 0) g[i].eb(j);
            }
            else if (b[j] % a[i] == 0) g[i].eb(j);
        }

    match.assign(m,-1);
    int minimun_vertex_cover = 0;
    for (int i = 0; i < n; i++){
        visit.assign(n,0);
        minimun_vertex_cover += Aug(i);
    }
    cout << "Case " << T << ": " << minimun_vertex_cover << '\n';

}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int T = 1; T <= t; T++) solve(T);
    return 0;
}