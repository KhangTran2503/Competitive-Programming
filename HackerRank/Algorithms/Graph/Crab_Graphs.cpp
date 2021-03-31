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
#define N 105
using namespace std;
const db Pi = acos(-1);
int C,n,T,m;
vi g[N];
int deg[N];

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> C;
    while (C--){
        cin >> n >> T >> m;
        for (int i = 1; i <= m; i++){
            int u,v;
            cin >> u >> v;
            g[u].pb(u);
            g[v].pb(v);
            deg[u] ++ , deg[v] ++ ;
        }
    }

    return 0;
}
