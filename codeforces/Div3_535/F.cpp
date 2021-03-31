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
#define prec(n) fixed<<setprecision(n)
#define sqr(x) (ll)(x)*(ll)(x)
#define lcm(a,b) ((ll)a/__gcd((ll)a,(ll)b)*(ll)(b))
#define gcd(a,b) __gcd(a,b)
#define oo (ll)(1e9)
#define N 2*int(1e5)+5
using namespace std;
const db Pi = acos(-1);
typedef  pair<int,ii> iii;
int par[N];
int n,m;
vector<iii> edge;
bool ok[N] = {0};

int arc(int u){
    if (u == par[u]) return u;
    else return par[u] = arc(par[u]);
}

void join(int u, int v){
    int U = arc(u), V = arc(v);
    par[U] = V;
}
int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge.pb(iii(w,ii(u,v)));
    }
    for (int i = 1; i <= n; i++) par[i] = i;
    sort(all(edge));
    /// nhung thang bang nhau va co the cho vao tap thi +=1
    /// nguoc lai -=1
    int ans = 0;
    for (int i = 0; i < sz(edge); i++){
        int w = edge[i].fir;
        int u = edge[i].sec.fir, v = edge[i].sec.sec;
        for (int j = i; j < sz(edge); j++)
            if (!ok[j] && edge[j].fir == w){
                if (arc(edge[j].sec.fir) != arc(edge[j].sec.sec)) ans++;
                ok[j] = 1;
            }
            else break;
        if (arc(u) != arc(v)){
            ans --;
            join(u,v);
        }
    }
    cout << ans;


    return 0;
}
