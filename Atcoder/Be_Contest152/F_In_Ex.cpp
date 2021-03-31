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
#define bitcount(n) __builtin_popcountll((ll)n)
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
vector<vector<ii>> g;
vector<ll> wedge;

int n, m;

// Inclusion-Exclusion

bool dfs(int u,int to,int id,int par = -1){
    if (u == to) return true;

    for (auto ev: g[u]){
        if (ev.fir == par) continue;
        if (dfs(ev.fir,to,id,u)){
            wedge[id] |= (1LL << ev.sec);
            return true;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
    }
    
    cin >> m;
    wedge.resize(m);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        dfs(u,v,i);
    }

    ll ans = (1LL << (n - 1));
    for (int mask = 1; mask < (1 << m); mask++){
        ll edge = 0;
        for (int i = 0; i < m; i++)
            if (getbit(mask,i)) edge |= wedge[i];
        int flip = (bitcount((ll)mask) & 1);
        if (flip) ans -= (ll)(1LL << (n - 1 - bitcount((ll)edge)));
        else ans += (ll)(1LL << (n - 1 - bitcount((ll)edge)));
    }
    cout << ans;
    return 0;
}