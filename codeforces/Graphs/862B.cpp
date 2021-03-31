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
#define N int(1e5)+5
using namespace std;
const db Pi = acos(-1);
vi g[N];
int n;
int color[N] = {0};
// Every Tree is Bipartite graph


void Bipartite(){
    color[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : g[u])
            if (!color[v]){
                color[v] = 3 - color[u];
                q.push(v);
            }
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    Bipartite();
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++)
        if (color[i] == 1) cnt1 ++;
        else cnt2 ++;
    ll ans = (ll)(cnt1)*(ll)(cnt2) - (ll)(n) +1LL;
    cout << ans;
    return 0;
}
