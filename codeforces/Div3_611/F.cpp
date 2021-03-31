// prufer code(basic)
#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> a(n - 1);
    vector<int> deg(n + 1,0);
    for (int &i: a) {
        cin >> i;
        deg[i]++;
    }

    vector<pair<int,int>> edge;
    
    set<int> leaf;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0) leaf.insert(i);

    for (int i = n - 2; i >= 0; i--){
        int u = a[i];
        int v = *leaf.begin();
        leaf.erase(v);
        edge.push_back(make_pair(u,v));
        deg[u]--;
        if (deg[u] == 0) leaf.insert(u);
    }
    
    reverse(edge.begin(),edge.end());
    cout << a[0] << '\n';
    for (pair<int,int> ans: edge) cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}