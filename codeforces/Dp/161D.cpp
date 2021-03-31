#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vector<vector<int>> g;
vector<vi> cnt;
int n, k; 
ll ans = 0;

void dfs(int u,int p){
    
    cnt[u][0] = 1;
    vector<ll> sum(k + 1,0);
    ll res = 0;
    for (int v: g[u]){
        if (v == p) continue;
        dfs(v,u);
        for (int i = 1; i <= k; i++) cnt[u][i] += cnt[v][i - 1];
        ans += cnt[v][k - 1]; // 1 nhanh bat dau tu u ket thuc tai v trong u
    
        if (k > 1)
            for (int i = 0; i <= k - 2; i++) res += cnt[v][i]*sum[k - 2 - i]; // di wa v1 ket thuc v2 trong subtree u
        for (int i = 0; i <= k; i++) sum[i] += cnt[v][i];

    }
    ans += res;
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    g.resize(n);
    cnt.resize(n,vi (k + 1));
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs(0,-1);
    cout << ans;
    return 0;
}