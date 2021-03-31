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
#define N 3*int(1e4)+5
using namespace std;
const db Pi = acos(-1);
vi g[N];
bool visit[N] = {0};
int n;
set<int> s;

int dfs(int u){
    visit[u] = 1;
    int tmp = 1;
    for (int v : g[u])
        if (!visit[v]) tmp += dfs(v);
    return tmp;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        s.insert(u);
        s.insert(v);
    }

    vi ans;
    for (auto u: s)
        if (!visit[u]) ans.pb(dfs(u));
    sort(all(ans));

    cout << ans[0] << ' ' << ans[sz(ans) - 1];
    return 0;
}
