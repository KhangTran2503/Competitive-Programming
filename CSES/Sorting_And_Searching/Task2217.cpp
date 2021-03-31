#include <bits/stdc++.h>
using namespace std;
int n, m;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    
    int ans = 1;
    int last = 0;
    for (int i = 1; i <= n; i++){
        if (pos[i] < last) ans++;
        last = pos[i];
    }

   // cout << ans << '\n';
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u,v);
        int x = a[u];
        int y = a[v];
        if (x >= 2 && pos[x - 1] > u && pos[x - 1] < v) ans--;
        if (x + 1 <= n && pos[x + 1] > u && pos[x + 1] < v) ans++;
        if (y >= 2 && pos[y - 1] > u && pos[y - 1] < v) ans++;
        if (y + 1 <= n && pos[y + 1] > u && pos[y + 1] < v) ans--;
        if (x + 1 == y) ans++;
        if (x - 1 == y) ans--;
        cout << ans << '\n';
        swap(a[u],a[v]);
        swap(pos[a[u]],pos[a[v]]);
    }


    return 0;
    
}
