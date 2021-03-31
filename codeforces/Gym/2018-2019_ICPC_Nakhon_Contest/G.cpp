#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> visit;
vector<int> choose;
vector<vector<int>> matrix;
int n;

void dfs(int u,int root){
    if (u != root) matrix[root][u] = 1;
    visit[u] = 1;
    for (int v: g[u])
        if (visit[v] == 0) dfs(v,root);
}


void solve(){
    int n, m;
    cin >> n;
    cin >> m;
    g.assign(n,vector<int>());
    matrix.assign(n,vector<int> (n,0));
    visit.assign(n,0);
    choose.assign(n,0);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 0; i < n; i++){
        visit.assign(n,0);
        dfs(i,i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (choose[i] == 0){
            ans++;
            for (int j = i + 1; j < n; j++)
                if (matrix[i][j] == 1 && matrix[j][i] == 1) choose[j] = 1;
        }
    cout << ans << '\n';
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
