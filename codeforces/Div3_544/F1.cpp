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
#define oo (ll)(1e9)
#define N 2*int(1e5) + 5
using namespace std;
const db Pi = acos(-1);
bool visit[N];
int n, m;
vi g[N];
int deg[N];

void bfs(int s){
    queue<int> q;
    q.push(s);
    ms(visit, 0);
    visit[s] = 1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : g[u])
            if (!visit[v]){
                cout << u << ' ' << v << '\n';
                visit[v] = 1;
                q.push(v);
            }
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        deg[u] ++; deg[v]++;
    }

    int degmax = 0, id = 0;
    for (int i = 1; i <= n; i++)
        if (deg[i] > degmax){
            degmax = deg[i];
            id = i;
        }
    bfs(id);

    return 0;
}
