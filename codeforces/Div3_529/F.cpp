/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
//#define ii pair<int,int>
#define pb push_back
#define vi vector<int>
#define fir first
#define sec second
#define all(s) s.begin(),s.end()
#define uni(a) (a).erase(unique(all(a)),(a).end())
#define sz(a) int((a).size())
#define ms(s,val) memset(s,val,sizeof(s))
#define bitcount(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N 2*int(1e5)+5
using namespace std;
typedef pair<int,int> ii;
typedef pair<ll,ii> iii;
vector<iii> e;
ll a[N];
int par[N];
int n,m;

int findset(int u){
    return (par[u] == u ? u : par[u] = findset(par[u]));
}

void join(int u,int v){
    par[findset(u)] = findset(v);
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        e.pb(iii(w,ii(u,v)));
    }
    int idmin = min_element(a+1,a+1+n)-a;
    for (int i = 1; i <= n; i++)
        if (idmin != i){
            e.pb(iii(a[idmin]+a[i],ii(idmin,i)));
        }
    sort(e.begin(),e.end());
    for (int i = 1; i <= n; i++) par[i] = i;

    ll res = 0;
    for (auto edge : e){
        int u = edge.second.first,
            v = edge.second.second;
        ll w = edge.first;
        if (findset(u) != findset(v)){
            res += w;
            join(u,v);
        }

    }
    cout << res;
    return 0;
}
