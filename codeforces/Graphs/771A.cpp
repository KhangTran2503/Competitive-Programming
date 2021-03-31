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
#define N 150005
using namespace std;
const db Pi = acos(-1);
int par[N];
ll sz[N], edge[N] = {0};
int n,m;

int findset(int u){
    if (u == par[u]) return u;
    else return par[u] = findset(par[u]);
}

void Unionset(int u,int v){
    int U = findset(u), V = findset(v);
    if (U == V){
        edge[U] ++;
        return;
    }
    ll tmp = edge[U] + edge[V];
    sz[U] += sz[V];
    par[V] = U;
    edge[U] = tmp + 1;
}

bool check(int u){
    int U = findset(u);
    ll tmp = sz[U]*(sz[U] - 1) / 2;
    return (edge[U] == tmp);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        Unionset(u,v);
    }

    bool ok = 1;
    for (int i = 1; i <= n; i++)
        ok &= check(i);
    if (ok) cout << "YES";
    else cout << "NO";
    return 0;
}
