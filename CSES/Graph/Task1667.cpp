#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> trace;
int n, m;

void bfs(int u){
    vector<int> dis(n);
    queue<int> q;
    dis[0] = 1;
    trace[0] = -1;
    q.push(0);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v: g[u])
            if (dis[v] == 0){
                dis[v] = dis[u] + 1;
                trace[v] = u;
                q.push(v);
            }
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);

    }

    trace.assign(n,-1);
    bfs(0);
    if (trace[n - 1] == -1) cout << "IMPOSSIBLE";
    else {
        vector<int> ans;
        int u = n - 1;
        while (u != -1){
            ans.emplace_back(u);
            u = trace[u];
        }

        reverse(ans.begin(),ans.end());
        cout << (int)ans.size() << '\n';
        for (int x: ans) cout << x + 1 << ' ';
    }
    return 0;
}
