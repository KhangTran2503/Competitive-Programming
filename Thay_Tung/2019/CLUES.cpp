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
#define lcm(a,b) ((ll)(a)/__gcd((ll)(a),(ll)(b))*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
using namespace std;
const db Pi = acos(-1);
int n , m , p;
int cnt = 0;
vector<vector<int>> g;
vector<int> used(n);

void dfs(int u,int col){
    used[u] = col;
    for(int v : g[u])
        if (used[v] == -1) dfs(v,col);
}

ll fastpow(ll x,ll y){
    ll res = 1;
    while (y > 0){
        if (y & 1) res = (res * x) % p;
        x = (x * x) % p;
        y >>= 1;
    }
    return res;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m >> p;
    g.resize(n);
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--, y --;
        g[x].pb(y);
        g[y].pb(x);
    }
    used.resize(n,-1);
    for (int u = 0; u < n; u++)
        if (used[u] == -1){
            cnt ++;
            dfs(u,cnt - 1);
        }
    vector<int> cntcom(cnt);
    for (int u = 0; u < n; u++) cntcom[used[u]] ++;
    if (cnt == 1) cout << 1 % p;
    else {
        ll ans = fastpow((ll)n,(ll)(cnt - 2));
        for (int lt = 0; lt < cnt; lt ++) ans = (ans * (ll)cntcom[lt]) % p;
        cout << ans;
    }
    return 0;
}
