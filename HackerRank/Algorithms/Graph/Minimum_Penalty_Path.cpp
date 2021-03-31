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
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N int(1e3)+5
using namespace std;
const db Pi = acos(-1);
vector<ii> g[N];
bool visit[N][1024];
int n, m;
int A, B;

void dfs(int u,int cost){
    visit[u][cost] = 1;
    for (ii uv : g[u]){
        int w = uv.fir, v = uv.sec;
        if (!visit[v][cost | w]) dfs(v,cost | w);
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].pb(ii(w,v));
        g[v].pb(ii(w,u));
    }
    cin >> A >> B;
    dfs(A,0);
    for (int i = 0; i < 1024; i++)
        if (visit[B][i]){
            cout << i;
            return 0;
        }
    cout << -1;
    return 0;
}
