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
vector<vector<int>> g;
int n;
int node1, node2, node3, ans;

int bfs1(int from,int &x,vector<int> &path){
    vector<int> dis(n,0);
    vector<int> trace(n);
    queue<int> q;

    q.push(from);
    dis[from] = 1;
    trace[from] = -1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v: g[u])
            if (!dis[v]){
                dis[v] = dis[u] + 1;
                trace[v] = u;
                q.push(v);
            }
    }

    x = 0;
    for (int u = 0; u < n; u++)
        if (dis[u] > dis[x]) x = u;

    path = {};
    int u = x;
    while (u != -1){
        path.emplace_back(u);
        u = trace[u];
    }
    return dis[x] - 1;


}

int bfs2(vector<int> path,int &x){
    queue<int> q;
    vector<int> dis(n);
    for (int u: path){
        dis[u] = 1;
        q.push(u);
    }

    while (!q.empty()){                
        int u = q.front();
        q.pop();
        for (int v: g[u])
            if (!dis[v]){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
    }

    x = 0;
    for (int u = 0; u < n; u++)
        if (u != node1 && u != node2&& dis[u] >= dis[x]) x = u;
    return dis[x] - 1;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<int> path(n);
    bfs1(0,node1,path);
    ans = bfs1(node1,node2,path);
    ans += bfs2(path,node3);
    cout << ans << '\n';
    cout << node1 + 1 << ' ' << node2 + 1 << ' ' << node3 + 1; 
    return 0;
}