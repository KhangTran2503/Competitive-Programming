#include <bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> box;
vector<int> ans;
int n, q;

int findset(int u){ return (u == par[u]) ? u: par[u] = findset(par[u]);}
void Union(int u,int v){
    int U = findset(u);
    int V = findset(v);
    if (U == V) return;
    par[U] = V;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    par.resize(n + 1);
    box.resize(n + 1);
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= n; i++) box[i] = i;
    while (q--){
        int s, t;
        cin >> s >> t;
        if (box[t] == 0) box[t] = box[s];
        else Union(box[s],box[t]);
        box[s] = 0;
    }
    ans.resize(n + 1);
    for (int i = 1; i <= n; i++)
        if (box[i]) ans[box[i]] = i;

    for (int i = 1; i <= n; i++) cout << ans[findset(i)] << ' ';    
    return 0;
}