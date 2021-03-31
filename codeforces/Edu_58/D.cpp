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
set<int> di[N];
map<int,int> dp[N];
int okprime[N]={0};
vi g[N];
int n;
int a[N];
int ans = 0;

///QHD tim duong kinh tren cay

/// tao them moi dinh la cac uoc nguyen to
/// dp[u][x] la duong di thang dai nhat qa uoc x

void Era(){

    for (int i = 2; i*i <= N-5; i++)
        if (okprime[i] == 0)
        for (int j = i*i; j <= N-5; j+=i ) okprime[j] = i;
}

int dfs(int u,int p){

    for (int v : g[u]){
        if (v == p) continue;
        dfs(v,u);
    }

    for (auto x: di[a[u]]){
        vi fmax;
        for (int v : g[u]){
            if (v != p) fmax.pb(dp[v][x]);
        }
        sort(rall(fmax));
        dp[u][x] = 1;
        if (!fmax.empty()) dp[u][x] += fmax[0];
        ans = max(ans,dp[u][x]);
        if (fmax.size() > 1) ans = max(ans, fmax[0] + fmax[1] +1);
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    Era();

   bool ok = false;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        int u = a[i];

        int cnt = 0;
        while (okprime[u] > 0){
            di[a[i]].insert(okprime[u]);

            u/= okprime[u];
        }
        if (u > 1) di[a[i]].insert(u);

        if (a[i] > 1) ok = true;
    }

    for (int i = 1; i < n; i++){
        int x,y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    if (!ok) {
        cout << 0;
        return 0;
    }
    dfs(1,0);
    cout << ans;
    return 0;
}
