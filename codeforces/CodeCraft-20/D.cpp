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
int n;
char dir[] = {'U','L','R','D','X'};
int dx[] = {-1,0,0,1},
    dy[] = {0,-1,1,0};
vector<vector<ii>> a;
vector<vector<int>> ans;

bool inside(int u,int v){
    return (u >= 1 && u <= n && v >= 1 && v <= n);
}

void dfs(int u,int v,int k){
    ans[u][v] = k;
    for (int h = 0; h < 4; h++){
        int _u = u + dx[h];
        int _v = v + dy[h];
        if (inside(_u,_v) && (ans[_u][_v] == -1) && a[u][v] == a[_u][_v]) dfs(_u,_v,3 - h);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n + 1,vector<ii> (n + 1));
    ans.resize(n + 1,vector<int> (n + 1,-1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j].fir >> a[i][j].sec;

    // check inf cycle
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == make_pair(-1,-1)){
                bool ok = false;
                for (int k = 0; k < 4; k++){
                    int u = i + dx[k];
                    int v = j + dy[k];
                    if (inside(u,v) && a[u][v] == make_pair(-1,-1)){
                        ans[i][j] = k;
                        ok = true;
                        break;
                    }
                }
                if (!ok){
                        cout << "INVALID";
                        return 0;
                }
            }
            else if (a[i][j] == make_pair(i,j)) dfs(i,j,4); 

    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (ans[i][j] == -1){
                cout << "INVALID";
                return 0;
            }
    cout << "VALID\n";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) cout << dir[ans[i][j]];
        cout << '\n';
    }
    return 0;
}