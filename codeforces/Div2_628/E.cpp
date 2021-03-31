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
const int Maxn = int(1e6) + 5;
vi prime(Maxn);
vi d(Maxn);
vector<vi> g(Maxn);
vi vertex;
int n;

// create graph with vertex is primenumber and edge (p,q) if exit p*q
void Era(){
    for (int i = 2; i < Maxn; i++)
        if (!prime[i]){
            prime[i] = i;
            for (ll j = (ll)i*(ll)i; j < Maxn; j += i) prime[j] = i;
        }
}

bool add_edge(int x){
    if (x == 1) return  false;

    unordered_map<int,int> cnt;
    while (x > 1){
        cnt[prime[x]]++;
        x /= prime[x];
    }
    vi v;
    for (auto it: cnt)
        if (it.sec & 1) v.eb(it.fir);
    
    if (v.empty()) return false;

    if (sz(v) == 1) v.eb(1);
    g[v[0]].eb(v[1]);
    g[v[1]].eb(v[0]);
    vertex.eb(v[0]);
    vertex.eb(v[1]);
    return true;
}


int bfs(int u){
    for (int u: vertex) d[u] = 0;
    queue<ii> q;
    q.push({u,-1});
    d[u] = 1;
    int res = INF;
    while (!q.empty()){
        int u = q.front().fir;
        int par = q.front().sec;
        q.pop();
        for (int v: g[u])
            if (v != par){
                if (!d[v]){
                    d[v] = d[u] + 1;
                    q.push({v,u});
                }
                else {
                    res = min(res,d[u] + d[v] - 1);
                }
            }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Era();
    int n;
    cin >> n;
    int maxai = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        maxai = max(maxai,x);
        if (!add_edge(x)){
            cout << 1;
            return 0;
        }
    }

    int ans= INF;
    sort(all(vertex));
    uni(vertex);
    for (int u: vertex) 
        if ((ll)u*(ll)u <= maxai) ans = min(ans,bfs(u));
    
    if (ans != INF) cout << ans;
    else cout << -1;
    return 0;
}