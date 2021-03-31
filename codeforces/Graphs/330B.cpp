/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ii pair<int,int>
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
#define N 1005
using namespace std;
int g[N][N]={0};
int n, m;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    int res = int(oo);
    int id;
    for (int u = 1; u <= n; u++){
        bool ok = true;
        for (int v = 1; v <= n; v++)
            if (u != v){
                if (g[u][v]) {
                    ok = false;
                    break;
                }
            }
        if (ok) id = u;
    }

    cout << n-1 << '\n';
    for (int i = 1 ; i <= n; i++)
        if (i != id) cout << id <<' '<<i << '\n';

    return 0;
}
