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
int dy[] = {1,-1,0,0};
int h, w;
vector<vi> g;
vi visit, match;

bool inside(int u,int v){
    return u >= 0 && u < h && v >= 0 && v < w;
}


int Aug(int u){
    if (visit[u] == 1) return 0;
    visit[u] = 1;
    for (int v: g[u])
        if (match[v] == -1 || Aug(match[v])){
            match[v] = u;
            return 1;
        }

    return  0;
}


void solve(){
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char> (w));

    int all = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            if (a[i][j] == '*') all++;
        }

    g.assign(h*w,vector<int> ());
    vi lef_vx;
    

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (a[i][j] == '*' && (i + j) % 2 == 1){
                int idx = i*w + j;
                for (int k = 0; k < 4; k++){
                    int u = i + dx[k];
                    int v = j + dy[k];
                    if (inside(u,v) && a[u][v] == '*') g[idx].eb(u*w + v);
                }
                lef_vx.eb(idx);
            }

    match.assign(h*w,-1);
    visit.assign(h*w,0);

    int maxmatch = 0;
    for (int u: lef_vx){
        maxmatch += Aug(u);
        for (int v: lef_vx) visit[v] = 0;
    }

    cout << all - maxmatch << '\n';
    
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}