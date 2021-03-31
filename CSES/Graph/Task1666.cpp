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
vi visit;
int n, m;

void dfs(int u){
    visit[u] = 1;
    for (int v: g[u])
        if (!visit[v]) dfs(v);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    g.resize(n);
    visit.resize(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].eb(b);
        g[b].eb(a);
    }

    vi ans;
    for (int i = 0; i < n; i++)
        if (!visit[i]){
            ans.eb(i);
            dfs(i);
        }
    
    cout << sz(ans) - 1 << '\n';
    for (int i = 1; i < sz(ans); i++) cout << ans[i - 1] + 1 << ' ' << ans[i] + 1 << '\n';

    return 0;
}