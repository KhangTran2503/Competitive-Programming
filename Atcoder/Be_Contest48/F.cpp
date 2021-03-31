// xem tutorial
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> g;
int n, U, V;


vector<int> bfs(int u){
    vector<int> d(n,0);
    queue<int> q;
    d[u] = 1;
    q.push(u);
    while (!q.empty()){
        int s = q.front();
        q.pop();
        for (int v: g[s])
            if (!d[v]){
                d[v] = d[s] + 1;
                q.push(v);
            }
    }


    return d;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    g.resize(n);

    cin >> U >> V;
    U--, V--;
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<int> dist_U = bfs(U);
    vector<int> dist_V = bfs(V);
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (dist_U[i] < dist_V[i])
            ans = max(ans, dist_V[i]);

    cout << ans - 2;        
    return 0;
}