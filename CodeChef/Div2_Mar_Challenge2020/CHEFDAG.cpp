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

// chua xong

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> num(n + 1, vi(k));
    vector<vector<bool>> g(n + 1, vector<bool>(n + 1, false));
    vector<vector<int>> a(k,vector<int> (n + 1));
    for (int i = 0; i < k; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];

    for (int i = 0; i < k; ++i)
        for (int j = 1; j <= n; ++j) num[a[i][j]][i] = j;

    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; ++j) {
            int chk = 1;
            for (int l = 0; l < k; ++l)
                if (num[i][l] <= num[j][l]) chk = 0;
            if (chk) g[j][i] = true;
        }
    

    vector<int> degin(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) degin[j] += (int)g[i][j];
    
    int cnt = 0;
    queue<int> q;
    for (int u = 1; u <= n; u++)
        if (degin[u] == 0) {
            q.push(u);
            cnt++;
        }

    vector<int> ans(n + 1);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        bool ok = false;
        for (int v = 1; v <= n; v++)
            if (g[u][v]){
                if (--degin[v] == 0){
                    q.push(v);
                    if (!ok){
                        ans[u] = v;
                        ok = true;
                    }
                    else cnt++;
                }
            }
    }
    cout << cnt << '\n';
    for (int u = 1; u <= n; u++) cout << ans[u] << ' ';
    cout << '\n'; 
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}