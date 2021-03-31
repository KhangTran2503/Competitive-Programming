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

void solve(){
    int n, d;
    cin >> n >> d;
    vector<vector<int>> depth(n);
    for (int i = 0; i < n; i++) depth[i].eb(i);

    int high = n - 1, low = 1;
    int edge = n*(n - 1)/2;
    // keo len layer phia tren la giam edge 1 don vi
    // khi full thi tang layer
    while (edge > d && high > low){
        int layer = high;
        while (edge > d){
            edge--;
            depth[layer - 1].eb(depth[layer].back());
            depth[layer].pop_back();
            layer--;
            if (layer == low) break;
        }

        if (sz(depth[low]) == (1 << low)) low++;
        high--; 
    }
    if (edge != d){
        cout << "NO\n";
        return;
    }
    else {
        vector<int> par(n);
        for (int i = 1; i < n; i++){
            for (int j = 0; j < sz(depth[i]); j++){
                int p = depth[i - 1][j/2];
                int u = depth[i][j];
                par[u] = p;
            }
        }
        cout << "YES\n";
        for (int i = 1; i < n; i++) cout << par[i] + 1 << ' ';
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}