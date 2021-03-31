#include <bits/stdc++.h>

using namespace std;
const int maxN = 5e5 + 10;

typedef pair<int, int> ii;

vector<int> divisors[maxN];
int depth[maxN];
vector<ii> g[maxN];
int pw2[20];
int Height;


void Init() {
    pw2[0] = 1;
    for (int i = 1; i < 20; i++) pw2[i] = pw2[i - 1] << 1;
    
    int limits = 5e5;
    for (int i = 1; i <= limits; i++) {
        for (int j = i; j <= limits; j += i) {
            divisors[j].push_back(i);
        }
    }
}

int b[maxN][20];
long long dist[maxN];

void dfs(int u, int par) {
    b[u][0] = par;
    for (int i = 1; i <= Height; i++) {
        //int v = b[u][i];
        b[u][i] = b[b[u][i - 1]][i - 1];
    }
    for (auto &uv : g[u]) {
        int v = uv.first;
        int w = uv.second;
        if (v == par) continue;
        depth[v] = depth[u] + 1;
        dist[v] = dist[u] + w;
        dfs(v, u);
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for (int i = Height; i >= 0; i--) {
        if (k >= pw2[i]) {
            k -= pw2[i];
            u = b[u][i];
        }
    }
    if (u == v) return u;

    for (int i = Height; i >= 0; i--) {
        if (b[u][i] != b[v][i]) {
            u = b[u][i];
            v = b[v][i];
        }
    }
    
    return b[u][0];
}

long long getDist(int u, int v) {
    int root = LCA(u, v);
    return dist[u] + dist[v] - dist[root] * 2;
}

int label[maxN];
bool used[maxN] = {false};
vector<int> V[maxN];

void solve(){
    int n;
    while (cin >> n) {
        if (n == 0) break;
 
        vector<int> div;
        Height = ceil(log2(n));
        
        for (int i = 1; i <= n; i++) {
            cin >> label[i];
            for (int &x : divisors[label[i]]) {
                V[x].push_back(i);
                if (!used[x]) {
                    div.push_back(x);
                    used[x] = true;
                }
            }
            g[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        
        dfs(1, 0);
        long long res = 0;
        for (int &gcd : div) {
            int root = V[gcd][0];
            long long ans_dist = 0;
            int so_far = root;
            for (int &u : V[gcd]) {
                long long d = getDist(root, u);
                if (d > ans_dist) {
                    so_far = u;
                    ans_dist = d;
                }
            }
            for (int &u : V[gcd]) {
                long long d = getDist(so_far, u);
                ans_dist = max(ans_dist, d);
            }
            res = max(res, ans_dist * gcd);
            V[gcd].clear();
            used[gcd] = false;
        }
        cout << res << '\n';
    }
}


int main() {
  
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	Init();
    solve();
	return 0;
}