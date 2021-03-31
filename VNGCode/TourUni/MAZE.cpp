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
char a[1005][1005];
int visit[1005][1005] = {0};
int n;
vector<ii> p;

int dx[] = {0,0,-1,1},
    dy[] = {1,-1,0,0};
 

bool inside(int u,int v){
    return (u > 0) && (v > 0) && (u <= n) && (v <= n) && (visit[u][v] == 0);
}

bool dfs(int u,int v){
    visit[u][v] = 1;
    if (a[u][v] == '*' && make_pair(u,v) != p[0]) return true;
    for (int k =0; k < 4; k++){
        int _u =u + dx[k];
        int _v = v + dy[k];
        if (inside(_u,_v) && a[_u][_v] != '#') 
            if (dfs(_u,_v)) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == '*') p.eb(i,j);  
        }
    if (dfs(p[0].fir,p[0].sec)) cout << "YES";
    else cout << "NO\n";
    return 0;
}