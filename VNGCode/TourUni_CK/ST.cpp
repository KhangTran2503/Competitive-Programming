/*    ####################  */
/*   # I_LOVE_THUY_LINH #  */
/*  ####################  */
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double
#define ii pair<int,int>
#define pb push_back
#define eb emplace_back
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
#define bitcount(n) __builtin_popcountll(n)
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
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int n, m;
vector<vector<int>> a;
int visit[55][55][505];
int rt, ct, rs,cs;

bool inside(int u,int v){
    return (u >= 0 && u < n && v >= 0 && v < n);
}

bool dfs(int u,int v,int cost){
    if (cost < 0) return false;
    visit[u][v][cost] = 1;
    if (u == rs && v == cs) return true;
    for (int k = 0; k < 4; k++){
        int uu = u + dx[k];
        int vv = v + dy[k];
        if (inside(uu,vv)){
            int needcost = max(0,a[uu][vv] - a[u][v]);
            if (cost - needcost >= 0 && visit[uu][vv][cost - needcost] == 0) {
                if (dfs(uu,vv,cost - needcost)) return true;
            } 
        }
    }
    return false;
}

void solve(){
    cin >> m >> n;
    cin >> rt >> ct;
    cin >> rs >> cs;
    a.resize(n,vector<int> (n));
    ms(visit,0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    if (dfs(rt,ct,m)) cout << "DANHDUOC\n";
    else cout << "NAMSAU\n";
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}