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
vector<vector<int>> g;

int main(){
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    g.resize(n + 1);
    vector<int> deg(n + 1);
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
        deg[u]++; deg[v]++;
    }
    

    vector<bool> used(n + 1,0);
    queue<int> q;
    for (int u = 1; u <= n; u++)
        if (deg[u] == 1){
            q.push(u);
            used[u] = 1;
        }
    // Each query , lca two leaf
    for (int i = 0; i < n/2; i++){
        int u = q.front();
        q.pop();
        int v = q.front();
        q.pop();
        cout << "? " << u << " " << v << endl;
        int x;
        cin >> x;
        if (x == -1) return 0;
        if (x == u || x == v){
            cout << "! " << x << endl;
            return 0;
        }

        for (int vertex: g[u])
            if (!used[vertex]){
                if (--deg[vertex] == 1) q.push(vertex);
            }
        
        for (int vertex: g[v])
            if (!used[vertex]){
                if (--deg[vertex] == 1) q.push(vertex);
            }
    }

    cout << "! " << q.front() << endl;
    return 0;
}